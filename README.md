# FNV decompilation

The decompilation of FNV, the Steam release for PC (version 1.4.0.525): C++ source code rebuilt function by function
from the game's executable. Built with the compilers the game was built with, every function listed in
`build/units.json` compiles to the same bytes as the original.

The project was spearheaded on [fnvdecomp.com](https://fnvdecomp.com), where a frozen version of the community
project stays online.

- **What it is for.** The modding community has kept working on FNV for more than a decade. This repository is meant
  for that community: for research, modding and game preservation, and only those purposes.
- **Source code only.** It contains no game files, no assets, no executables and nothing you can play, and nothing
  of the game is distributed here.
- **You need the game.** To use any of this you need to own the Steam version of FNV (1.4.0.525).
- **Trademarks** belong to their holders, listed under [Legal](#legal). This project is not affiliated with or
  endorsed by any of them.

## Contributing

Pull requests are welcome from anyone. Most of what is left is readability: many functions still have placeholder
names (`FUN_00xxxxxx`), vague names or no comment, and all of that can be improved without changing a single byte of
the output.

### The automatic check

Every pull request gets an automatic check, called `match`. It runs on GitHub's machines, involves no part of the
game, and has to pass before a pull request can be merged:

1. It finds the translation units your change can affect: the files you changed, every unit that includes them, and
   every unit whose entry in `build/units.json` changed.
2. It builds each of those units twice, from `main` and with your change, with the Microsoft compilers the game was
   built with.
3. Every function has to come out identical, at its original address: the same code bytes, and every call and data
   reference resolving to the same original address through `build/units.json`, exception-handling code included.
   A function that moved to another unit is compared with what it compiled to in its old unit. `main` matches the
   game byte for byte, so a change that passes still does.

What to expect:

- **Passes:** renaming functions, parameters, variables, types and fields; adding or improving comments;
  reformatting; restructuring headers and types; moving functions between units (see "Changing the build recipe"). A
  change only to comments, spacing or blank lines passes without a build.
- **Fails:** anything that changes what a function compiles to. The check lists the functions that differ by
  address; see what differs with your own copy of the game:
  `python3 tools/build_and_match.py --image <your FalloutNV.exe> --only <unit>`.
- **Needs a maintainer:** changes outside `src/`, `include/`, `build/units.json` and Markdown files (the tools, the
  workflow), and changes to `build/units.json` beyond what "Changing the build recipe" allows. The check fails on
  these and nobody can merge them, so open an issue instead. Changes to the tools and the workflow are made by the
  repository owner and verified against the game.

### Review and merging

A pull request is merged when the check passes and two reviewers have approved it:

- Nobody can skip the check, the repository owner included.
- Two approvals are needed. An approval is dropped when new commits arrive, and the last push has to be approved by
  someone other than the person who made it.
- The pull request has to be up to date with `main`. If `main` moves first, use "Update branch" and the check runs
  again on the combined code.

After every change to `main`, the whole of `main` is also built against the game's executable on the project's own
machine. That build proves `main` still matches the game byte for byte, not only that it compiles the same as
before.

### Renaming a function

`build/units.json` lists every function by its original address and its decorated (mangled) name. When you rename a
function, put its new decorated name at the same address, in every unit that lists it; otherwise the check reports
the old name as unbound. Adding a declaration or a string literal can renumber the compiler's string labels
(`$SG...`) that `build/units.json` names; the check says so when that is the cause.

A unit may also bind a name to an address it refers to, for example a global or a vtable that the code used to write
as a number: the check builds the unit again and the bytes at every function's address have to stay the same.
Exception-handling code resolves names through the whole of `build/units.json`, so when a pull request changes any
names there, the check also rebuilds every unit with exception-handling code. That adds a few minutes.

### Changing the build recipe

Besides names, a pull request may change how `build/units.json` builds the functions, because the check builds both
sides and compares every function at its address:

- add, remove or reorder units, and move functions from one unit to another;
- change a unit's compiler (`sp1`, `rtm` or `vc8`) or its compiler options, using only the options `main` already
  uses (listed in `FLAGS` in `tools/compare_builds.py`);
- a new unit's source is a `.c` or `.cpp` file in `src/` (or `third_party/`).

What has to stay: every function's address and size, each unit's `eh_tails` and `literal_symbols`, and `totals`
(apart from `units`, which is the number of units). A function that uses exception-handling code, itself or through
one of its `fold_aliases`, stays in the unit that lists its EH tails. A unit lists each address once, and a function's `fold_aliases` must compile to exactly the
same code as the function. A unit is identified by its source; when two units build the same source, by their order
among those. The tree may only hold regular files (no symlinks).

Exception-handling code is the one part the check cannot always follow: the game places it by its EH tables, not in
the order the compiler writes it. When a change reorders or reshapes it, the check reports "its EH tails". If the
full build against the game still matches, the owner builds the change against the game and adds its EH code to
`tools/verified_eh.json` in a pull request of their own; the check then accepts it.

### Never include any part of the game

No executable, no bytes copied from it, no object files built from this code, no game data. A pull request that
contains any of it is closed.

### Running the check yourself

With the compilers set up (see "What you need"), commit your change, then compare it with `main`:

    git fetch origin
    git worktree add --detach ../fnv-main origin/main      # main, to compare against
    git worktree add --detach ../fnv-scratch HEAD          # a scratch checkout the check builds in
    python3 tools/compare_builds.py plan ../fnv-main . --out ../plan.json --max-shards 1
    python3 tools/compare_builds.py shard ../fnv-scratch "$(git rev-parse origin/main)" "$(git rev-parse HEAD)" \
        --plan ../plan.json --shard 0 --out ../result.json
    python3 tools/compare_builds.py report --plan ../plan.json ../result.json

When `plan` reports no units to build, skip `shard` and run `report` without `../result.json`.

## Status

- Functions in scope: 70,611 of 70,611 match byte for byte.
- Bytes in scope: 11,537,067 of 11,537,067.

"In scope" leaves out code the compiler and linker generate on their own (runtime stubs, thunks, padding) and a small
list of entries in the executable that are not functions.

## What this is, and what it is not

- It is a reference: readable C++ that shows how the game works, and that reproduces the original machine code.
- It is not a port or a source port. The default build produces object files for comparison. The optional
  [custom exe build](#building-a-custom-exe) combines those objects with pieces taken from your own copy, on your
  own machine, into an exe you can play but must not share.
- It does not contain, and will not accept, tools or instructions for getting around the game's copy protection.
- It does not contain any part of the game's executable or data files. Addresses, function sizes and a few SHA-256
  fingerprints are the only facts about the executable in this repository.

## Names and comments

The function comments were written by machine: Qwen 27B proposed them from the matched code, and Codex Luna and
Claude Sonnet reviewed them. The text is kept as reviewed. Many function, parameter and variable names were proposed by
machine as well. Every such change was rebuilt and compared, so none of it changes a single byte of the output. The comments describe
what the code appears to do and can be wrong; the machine code is the authority. Corrections are welcome.

## What you need

1. **The game.** A legally owned copy of FNV for PC, version 1.4.0.525 (on Steam, app 22380, base game
   or Ultimate Edition).
2. **The plain executable of that version, from your own copy.** The comparison reads the original machine code. The
   Steam file as installed does not work: its code is encrypted on disk. This repository does not supply the
   executable, any part of it, or any way to produce it. Never share yours.
3. **Python 3.10 or newer.**
4. **Microsoft's compilers**, from Microsoft's own downloads (none are included here):
   - Visual C++ 2008 Express Edition with SP1 (cl 15.00.30729.01): almost every unit.
   - Visual C++ 2008 Express Edition, original release (cl 15.00.21022.08): the units `build/units.json` marks
     `"compiler": "rtm"` (the game itself was built with this one).
   - Visual C++ 2005 SP1 (cl 14.00.50727.762), from the Windows SDK for Windows Vista (February 2007 Update): the
     units marked `"compiler": "vc8"`.

   On Windows, install them. On Linux and macOS they run under Wine; see "Compilers without Windows" below.

## Build and compare

    export FNV_MSVC9_ROOT=/path/to/msvc9          # folder with VC/ and SDK/ (2008 SP1)
    export FNV_MSVC9_RTM_ROOT=/path/to/msvc9rtm   # 2008 original release
    export FNV_MSVC8_ROOT=/path/to/msvc8          # 2005 SP1
    export FNV_MSVC9_PREFIX=/path/to/wineprefix   # not needed on Windows

    python3 tools/build_and_match.py --image /path/to/your/FalloutNV.exe

The image is checked first against a few fingerprints; nothing runs on any other file. Every unit is then compiled
and every function compared, relocations included. The result is a count of matching functions and bytes, and a list
of anything that does not match. `--only <text>` builds the units whose path contains the text, `--jobs N` sets how
many compile at once, and `--out results.json` writes the per-unit results (addresses and counts only, never bytes of
your executable).

A full run compiles about 3,000 units; expect it to take a while.

## Building a custom exe

You can turn this source into a working `FalloutNV.exe` on your own machine and play the game with it. This is
optional: the normal build above only produces object files to compare.

**Why build one.** It is the same approach other decompilation projects use for console games: the repository holds
only reconstructed code, and your own copy of the game supplies everything else when you build. A custom exe lets you
change the game's code and see the effect in the game, add logging or debug checks, test fixes, and step through
readable source in a debugger. Every compiled function in it is the byte-matching code checked by this repository.

**What it is not.** It is not a replacement you can share, and it does not remove the need to own the game: the
build reads your own copy, and the exe runs only with your installed game and its data. The part of the exe that is
not yet source (some data tables, resources and runtime code) is taken from your copy at build time and never leaves
your machine.

**How finished it is.** The custom exe starts, reaches the main menu, loads saves and has been played through
dialogue, bartering, combat, VATS, fast travel, sleeping and saving. Most of the game has not been tested with it.
Some connections between rebuilt code and data (links) may still point at the wrong thing; they usually show up as a
crash or as something behaving differently from the original game. Mods and script extenders (NVSE and its plugins)
are untested. Please report problems: see [Reporting crashes and bad links](#reporting-crashes-and-bad-links).

### What you need

- Windows 10 or 11. Wine is untested.
- 64-bit Python 3.10 or newer, with `capstone` and `psutil` (`python -m pip install capstone psutil`).
- All three Microsoft compilers described in [What you need](#what-you-need) above.
- The **plain** `FalloutNV.exe` from your own copy of Fallout: New Vegas PC 1.4.0.525 (for example the GOG release).
  The encrypted Steam executable does not work, and these tools contain no decryption or copy-protection bypass. Your
  exe is checked against `build/image_check.json` before anything is extracted.
- About 5 GB of free disk space and at least 3 GB of free memory while building.

### Build it

From the repository root, in PowerShell (replace the example paths with your own):

```powershell
$env:FNV_MSVC9_ROOT = 'C:/compilers/msvc9'       # VC/ and SDK/, 2008 SP1
$env:FNV_MSVC9_RTM_ROOT = 'C:/compilers/msvc9rtm'
$env:FNV_MSVC8_ROOT = 'C:/compilers/msvc8'
# If the compiler helper DLLs are not beside cl.exe, add their installed folder:
$env:PATH = 'C:/Program Files (x86)/Microsoft Visual Studio 9.0/Common7/IDE;' + $env:PATH
python tools/link/custom_exe.py extract --image 'C:/my-own-copy/FalloutNV.exe' --jobs 4
python tools/link/custom_exe.py build
```

1. `extract` compiles every unit (like a full `build_and_match.py` run, so expect it to take a while), checks that all
   of them still match, and then takes from your exe only what the source does not provide yet: data tables (written
   out as C++), the remaining runtime code, and resources. Run it again whenever source, headers or the recipe change.
2. `build` compiles that, links everything with the VC9 linker, and checks the result (imports, pointers, data, TLS,
   resources, loader settings). Only if every check passes does it write `.local/custom-exe/FalloutNV_src.exe`.

Everything generated lives in the git-ignored `.local/custom-exe/` folder. The tools never write into your game
folder and never replace your original exe. They use at most eight compiler processes and pause if free memory drops
below 3 GB. If `extract` or `build` reports a failure, do not use the output; see the reporting section below.

**Never share the custom exe, object files or anything under `.local/`.** They contain parts of your game. None of it
belongs in a commit, an issue or a crash report.

### Play it

```powershell
python tools/link/custom_exe.py run --game-dir 'C:/Games/Fallout New Vegas' --timeout 14400
```

This starts the custom exe with your game folder as its working directory, under a small debugger that records
crashes. `--timeout` is in seconds (at most 14400, four hours); quit the game normally before it runs out, or the
launcher closes it. During the run your installed game files are opened read-only, and afterwards the launcher checks
that none of them changed.

**Your saves.** Before the run the launcher backs up the fixed-name saves (`autosave` and `quicksave`) and restores
them afterwards, so a crash cannot leave you with a broken autosave. That also means autosaves and quicksaves made
during the run are put back to what they were. **Use normal (numbered) saves to keep progress made with the custom
exe.** The run's own versions are kept in that run's report folder.

The launcher only starts the game once it is sure the backup is safe. It refuses to start, with an error saying why,
when:

- your saves are not in the default folder (`Documents/My Games/FalloutNV/Saves`): any `SLocalSavePath` other than
  `Saves\`, or `bUseMyGamesDirectory=0`, in `Fallout_default.ini`, `Fallout.ini`, `FalloutPrefs.ini` or
  `FalloutCustom.ini`. Custom save folders are not supported yet. Mod managers that redirect saves without changing
  these files (for example a virtual file system) are not detected, so run the custom exe without them;
- `My Games/FalloutNV` does not exist yet (start the original game once first);
- a backed-up file cannot be read back with the same contents.

If putting the saves back fails after a run, the launcher says so (`RESTORE FAILED`) and names the folder that holds
your original files. That folder is never deleted; copy the files back from it yourself before playing.

When the game exits, the launcher prints the path of the run report (`.local/custom-exe/runs/<time>/`). If the game
crashed, it also prints a line like:

```
UNHANDLED 0xc0000005 at 0x00a1b2c3: ?SomeFunction@SomeClass@@QAEXXZ+0x4f
```

That is the exception code, the address, and the function plus offset where it happened, looked up in the build's
`FalloutNV.map`. Lines starting with `first chance` are usually normal (the game handles them itself); the
`UNHANDLED` line is the crash.

To check that the build tools themselves work, without the game or the compilers:

```powershell
python -m unittest discover -s tools/link/tests -v
```

### Reporting crashes and bad links

A crash or wrong behaviour in the custom exe that does not happen with the original exe usually means a bad link:
rebuilt code connected to the wrong function or data. These are found by people playing, so reports help a lot.

**Before reporting:**

1. Update to the latest `main`, run `extract` and `build` again, and check that the problem still happens.
2. Turn off all mods and script extenders (NVSE and its plugins).
3. Try the same thing with your **original** exe from the same save. If it happens there too, it is a bug in the game,
   not in the custom exe.

**Open a GitHub issue** titled `Custom exe: <what happened>` and include:

- the source revision: the output of `git rev-parse HEAD`;
- the `UNHANDLED` line the launcher printed (exception code, address, function and offset), if it crashed;
- what you did, step by step, starting from where (main menu, a new game, or a save and the place in the world);
- what you expected and what happened instead, if it did not crash (for example: wrong text, missing sound or
  texture, an item or quest behaving differently from the original);
- whether it happens every time, and whether it happens with the original exe;
- your Windows version, and the game version and store (for example GOG 1.4.0.525).

`debug_report.json` from the run folder is useful too. Read it before attaching it: it should contain only addresses,
exception codes and function names. **Do not attach** the custom exe, files from `.local/`, memory dumps, game files
or screenshots of disassembly. Do not attach a save unless a maintainer asks for one.

**For contributors fixing a report:** the function and offset point at the code that was running. Check it with
`python tools/build_and_match.py --image <your FalloutNV.exe> --only <unit>`. If the function still matches, the
problem is usually not that function's code but a link: a call, global, vtable or data reference that the custom
build connects to a different address than the original. A fix that changes compiled bytes must still pass the full
match check.

### Maintainers: reviewing changes to these tools

This feature changes build tools, so under the contribution rules it needs maintainer review and a full build against
the game. The ordinary `match` check reports **Needs a maintainer** for these tool changes even when affected code
compiles identically. Use clean checkouts for `compare_builds.py plan`: that upstream planner inventories all files,
including ignored build output. Keep `.local/` out of both comparison checkouts.

## Layout

| Path | What it holds |
|---|---|
| `src/` | The game's code and the libraries linked into it, as C++ translation units. |
| `include/` | Shared headers. |
| `third_party/zlib-1.2.1/` | zlib 1.2.1 under its own licence, with the game's changes to `inflate.c`; see `third_party/README.md`. |
| `patches/` | The game's changes to `inflate.c` as a diff against the official zlib file. |
| `build/units.json` | The build recipe: for each unit its source, compiler, flags and the functions it must reproduce. |
| `build/image_check.json` | SHA-256 fingerprints of a few functions, used to recognise the right executable. |
| `tools/` | The compiler wrapper, the COFF/PE comparison, `build_and_match.py` and `compare_builds.py` (the pull request check, see [Contributing](#contributing)). |
| `.github/` | The automatic check on pull requests. |

Some units appear in more than one variant (for example `*_ob1_variant.cpp`): the original was built with different
optimisation settings in different places, and each variant reproduces the functions built with its settings.

## Compilers without Windows

The compilers run under Wine (tested on Ubuntu 24.04 with Wine 9). No installer is needed: unpack the Express ISO
with 7-Zip, cabextract and msitools, and point `FNV_MSVC9_ROOT` at a folder holding `VC/` and `SDK/`:

    ISO=VS2008ExpressWithSP1ENUX1504728.iso; R=$PWD/msvc9
    7z x -y -otc "$ISO" VCExpress
    cabextract -q -d tc/ixp tc/VCExpress/Ixpvc.exe && (cd tc/ixp && msiextract -C ../vcx vs_setup.msi >/dev/null)
    V="tc/vcx/Program Files/Microsoft Visual Studio 9.0"; mkdir -p "$R"
    cp -r "$V/VC:Vc7" "$R/VC"
    for f in mspdb80.dll msobj80.dll mspdbcore.dll mspdbsrv.exe; do find "$V/Common7" -iname "$f" -exec cp {} "$R/VC/bin/" \; ; done
    cabextract -q -d tc/sdkx tc/VCExpress/WCU/WinSDK/WinSDK_Build.exe
    (cd tc/sdkx && msiextract -C ../sdko VistaClientHeadersLibs-x86.msi >/dev/null)
    S="tc/sdko/SOURCEDIR/Program Files/Microsoft SDKs:./Windows:./v6.0A:."; mkdir -p "$R/SDK"
    cp -r "$S/Include" "$R/SDK/Include"; cp -r "$S/Lib" "$R/SDK/Lib"

The original-release ISO (`VS2008ExpressENUX1397868.iso`) unpacks the same way into its own folder; reuse the SP1
`SDK/` folder for it. For Visual C++ 2005 SP1, unpack the `WinSDKCompiler-x86.msi` of the Windows SDK for Windows Vista
(February 2007 Update) and copy its `Bin`, `INCLUDE` and `LIB` folders to `VC/bin`, `VC/include` and `VC/lib`, reuse
the SP1 `SDK/` folder, and put the VC 2005 runtime DLLs next to `cl.exe` as the private assembly it asks for.

## Credits

This was a community effort, coordinated on [fnvdecomp.com](https://fnvdecomp.com). Contributors who chose to be named are listed in
`CREDITS.md` and as co-authors of the first commit.

## Legal

Fallout, Fallout: New Vegas, Bethesda, Bethesda Softworks and
ZeniMax are trademarks or registered trademarks of ZeniMax Media Inc., a Microsoft company, in the U.S. and/or other
countries. The game was developed by Obsidian Entertainment and published by Bethesda Softworks. Steam is a trademark
of Valve Corporation. The libraries linked into the game belong to their owners: Gamebryo (Gamebase Co., Ltd.), Havok
(Microsoft), SpeedTree (Interactive Data Visualization, Inc., part of Unity) and FaceGen (Singular Inversions Inc.);
zlib is by Jean-loup Gailly and Mark Adler. All other trademarks belong to their respective holders. This project is
not affiliated with or endorsed by any of them.

You need your own legally obtained copy of the game, and you are responsible for following its licence terms and the
law where you live.

If you hold rights in this material and want something changed or removed, write to contact@fnvdecomp.com. We will
respond promptly and comply.

No licence is granted for this repository; see `LICENSE`. `third_party/` keeps its own licence.
