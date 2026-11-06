
// src/gamebryo2.2/corelibs/nianimation/nianimationsdm.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nianimationsdm.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl FUN_00a63520(const char* pName);
void __cdecl RemovePostProcess(void(__cdecl* pfnCallback)());
void __cdecl FUN_00a42c80();
void __cdecl ClearNodeList();
void __cdecl ClearGlobalStrings();
void __cdecl ResetRegistry();
extern bool g_bInitialized_011f369d;

static const char s_sz00[] = "NiAlphaController";
static const char s_sz01[] = "NiBlendAccumTransformInterpolator";
static const char s_sz02[] = "NiBlendBoolInterpolator";
static const char s_sz03[] = "NiBlendColorInterpolator";
static const char s_sz04[] = "NiBlendFloatInterpolator";
static const char s_sz05[] = "NiBlendPoint3Interpolator";
static const char s_sz06[] = "NiBlendQuaternionInterpolator";
static const char s_sz07[] = "NiBlendTransformInterpolator";
static const char s_sz08[] = "NiBoneLODController";
static const char s_sz09[] = "NiBoolData";
static const char s_sz10[] = "NiBoolInterpolator";
static const char s_sz11[] = "NiBoolTimelineInterpolator";
static const char s_sz12[] = "NiBSplineBasisData";
static const char s_sz13[] = "NiBSplineData";
static const char s_sz14[] = "NiBSplineColorInterpolator";
static const char s_sz15[] = "NiBSplineCompColorInterpolator";
static const char s_sz16[] = "NiBSplineCompFloatInterpolator";
static const char s_sz17[] = "NiBSplineCompPoint3Interpolator";
static const char s_sz18[] = "NiBSplineCompTransformInterpolator";
static const char s_sz19[] = "NiBSplineFloatInterpolator";
static const char s_sz20[] = "NiBSplinePoint3Interpolator";
static const char s_sz21[] = "NiBSplineTransformInterpolator";
static const char s_sz22[] = "NiColorData";
static const char s_sz23[] = "NiColorExtraDataController";
static const char s_sz24[] = "NiColorInterpolator";
static const char s_sz25[] = "NiControllerManager";
static const char s_sz26[] = "NiControllerSequence";
static const char s_sz27[] = "NiFlipController";
static const char s_sz28[] = "NiFloatData";
static const char s_sz29[] = "NiFloatExtraDataController";
static const char s_sz30[] = "NiFloatInterpolator";
static const char s_sz31[] = "NiFloatsExtraDataController";
static const char s_sz32[] = "NiFloatsExtraDataPoint3Controller";
static const char s_sz33[] = "NiGeomMorpherController";
static const char s_sz34[] = "NiKeyframeController";
static const char s_sz35[] = "NiKeyframeData";
static const char s_sz36[] = "NiKeyframeManager";
static const char s_sz37[] = "NiLightColorController";
static const char s_sz38[] = "NiLightDimmerController";
static const char s_sz39[] = "NiLookAtController";
static const char s_sz40[] = "NiLookAtInterpolator";
static const char s_sz41[] = "NiMaterialColorController";
static const char s_sz42[] = "NiMorphData";
static const char s_sz43[] = "NiMultiTargetTransformController";
static const char s_sz44[] = "NiPathController";
static const char s_sz45[] = "NiPathInterpolator";
static const char s_sz46[] = "NiPoint3Interpolator";
static const char s_sz47[] = "NiPosData";
static const char s_sz48[] = "NiQuaternionInterpolator";
static const char s_sz49[] = "NiRollController";
static const char s_sz50[] = "NiRotData";
static const char s_sz51[] = "NiSequence";
static const char s_sz52[] = "NiSequenceStreamHelper";
static const char s_sz53[] = "NiStringPalette";
static const char s_sz54[] = "NiTextKeyExtraData";
static const char s_sz55[] = "NiTextureTransformController";
static const char s_sz56[] = "NiTransformController";
static const char s_sz57[] = "NiTransformData";
static const char s_sz58[] = "NiTransformInterpolator";
static const char s_sz59[] = "NiUVController";
static const char s_sz60[] = "NiUVData";
static const char s_sz61[] = "NiVisController";
static const char s_sz62[] = "BSAnimNotes";
static const char s_sz63[] = "BSGrabIKNote";
static const char s_sz64[] = "BSLookIKNote";
static const char s_sz65[] = "BSRotAccumTransfInterpolator";
static const char s_sz66[] = "BSTreadTransfInterpolator";
static const char s_sz67[] = "BSBlendTreadTransfInterpolator";
static const char s_sz68[] = "BSMultiTargetTreadTransfController";
static const char s_sz69[] = "BSFrustumFOVController";
static const char s_sz70[] = "NiVisData";
__declspec(selectany) extern const char g_szShutdownEnd[] = "";

// @fnv 0x00a2de70
void __cdecl ShutdownAnimationClasses()
{
    if (!g_bInitialized_011f369d)
        return;
    g_bInitialized_011f369d = false;
    FUN_00a63520(s_sz00);
    FUN_00a63520(s_sz01);
    FUN_00a63520(s_sz02);
    FUN_00a63520(s_sz03);
    FUN_00a63520(s_sz04);
    FUN_00a63520(s_sz05);
    FUN_00a63520(s_sz06);
    FUN_00a63520(s_sz07);
    FUN_00a63520(s_sz08);
    FUN_00a63520(s_sz09);
    FUN_00a63520(s_sz10);
    FUN_00a63520(s_sz11);
    FUN_00a63520(s_sz12);
    FUN_00a63520(s_sz13);
    FUN_00a63520(s_sz14);
    FUN_00a63520(s_sz15);
    FUN_00a63520(s_sz16);
    FUN_00a63520(s_sz17);
    FUN_00a63520(s_sz18);
    FUN_00a63520(s_sz19);
    FUN_00a63520(s_sz20);
    FUN_00a63520(s_sz21);
    FUN_00a63520(s_sz22);
    FUN_00a63520(s_sz23);
    FUN_00a63520(s_sz24);
    FUN_00a63520(s_sz25);
    FUN_00a63520(s_sz26);
    FUN_00a63520(s_sz27);
    FUN_00a63520(s_sz28);
    FUN_00a63520(s_sz29);
    FUN_00a63520(s_sz30);
    FUN_00a63520(s_sz31);
    FUN_00a63520(s_sz32);
    FUN_00a63520(s_sz33);
    FUN_00a63520(s_sz34);
    FUN_00a63520(s_sz35);
    FUN_00a63520(s_sz36);
    FUN_00a63520(s_sz37);
    FUN_00a63520(s_sz38);
    FUN_00a63520(s_sz39);
    FUN_00a63520(s_sz40);
    FUN_00a63520(s_sz41);
    FUN_00a63520(s_sz42);
    FUN_00a63520(s_sz43);
    FUN_00a63520(s_sz44);
    FUN_00a63520(s_sz45);
    FUN_00a63520(s_sz46);
    FUN_00a63520(s_sz47);
    FUN_00a63520(s_sz48);
    FUN_00a63520(s_sz49);
    FUN_00a63520(s_sz50);
    FUN_00a63520(s_sz51);
    FUN_00a63520(s_sz52);
    FUN_00a63520(s_sz53);
    FUN_00a63520(s_sz54);
    FUN_00a63520(s_sz55);
    FUN_00a63520(s_sz56);
    FUN_00a63520(s_sz57);
    FUN_00a63520(s_sz58);
    FUN_00a63520(s_sz59);
    FUN_00a63520(s_sz60);
    FUN_00a63520(s_sz61);
    FUN_00a63520(s_sz62);
    FUN_00a63520(s_sz63);
    FUN_00a63520(s_sz64);
    FUN_00a63520(s_sz65);
    FUN_00a63520(s_sz66);
    FUN_00a63520(s_sz67);
    FUN_00a63520(s_sz68);
    FUN_00a63520(s_sz69);
    FUN_00a63520(s_sz70);
    RemovePostProcess(FUN_00a42c80);
    ClearNodeList();
    ClearGlobalStrings();
    ResetRegistry();
}

extern bool DAT_011f369d;
void FUN_00a64900(const char*, void (*)());
void FUN_00a64920(void (*)());
void FUN_00a42c80();
void FUN_00a421c0();
extern const char DAT_01096060[];  // NiAlphaController
void CreateFloatInterpController();
extern const char DAT_0109603c[];  // NiBlendAccumTransformInterpolator
void FUN_00a39700();
extern const char DAT_01096024[];  // NiBlendBoolInterpolator
void FUN_00a565c0();
extern const char DAT_01096008[];  // NiBlendColorInterpolator
void CreateBlendColorInterpolator();
extern const char DAT_01095fec[];  // NiBlendFloatInterpolator
void CreateNiBlendFloatInterpolator();
extern const char DAT_01095fd0[];  // NiBlendPoint3Interpolator
void FUN_00a55a80();
extern const char DAT_01095fb0[];  // NiBlendQuaternionInterpolator
void FUN_00a55470();
extern const char DAT_01095f90[];  // NiBlendTransformInterpolator
void FUN_00a409d0();
extern const char DAT_01095f7c[];  // NiBoneLODController
void CreateBoneLODController();
extern const char DAT_01095f70[];  // NiBoolData
void FUN_00a537f0();
extern const char DAT_01095f5c[];  // NiBoolInterpolator
void CreateNiKeyBasedInterpolator();
extern const char DAT_01095f40[];  // NiBoolTimelineInterpolator
void CreateBoolInterpolator();
extern const char DAT_01095f2c[];  // NiBSplineBasisData
void CreateNiSplineImpl();
extern const char DAT_01095f1c[];  // NiBSplineData
void FUN_00a51e10();
extern const char DAT_01095f00[];  // NiBSplineColorInterpolator
void FUN_00a51c60();
extern const char DAT_01095ee0[];  // NiBSplineCompColorInterpolator
void CreateSplineCompColorInterpolator();
extern const char DAT_01095ec0[];  // NiBSplineCompFloatInterpolator
void FUN_00a51620();
extern const char DAT_01095ea0[];  // NiBSplineCompPoint3Interpolator
void CreateComp4();
extern const char DAT_01095e7c[];  // NiBSplineCompTransformInterpolator
void CreateEvaluator();
extern const char DAT_01095e60[];  // NiBSplineFloatInterpolator
void FUN_00a50ad0();
extern const char DAT_01095e44[];  // NiBSplinePoint3Interpolator
void FUN_00a50840();
extern const char DAT_01095e24[];  // NiBSplineTransformInterpolator
void FUN_00a50180();
extern const char DAT_01095e18[];  // NiColorData
void CreateNiColorData();
extern const char DAT_01095dfc[];  // NiColorExtraDataController
void FUN_00a4fac0();
extern const char DAT_01095de8[];  // NiColorInterpolator
void FUN_00a3c130();
extern const char DAT_01095dd4[];  // NiControllerManager
void FUN_00a2f6c0();
extern const char DAT_01095dbc[];  // NiControllerSequence
void FUN_00a326c0();
extern const char DAT_01095da8[];  // NiFlipController
void CreateNiFlipController();
extern const char DAT_01095d9c[];  // NiFloatData
void CreateNiFloatData();
extern const char DAT_01095d80[];  // NiFloatExtraDataController
void FUN_00a411f0();
extern const char DAT_01095d6c[];  // NiFloatInterpolator
void CreateNiFloatInterpolator();
extern const char DAT_01095d50[];  // NiFloatsExtraDataController
void FUN_00a4f000();
extern const char DAT_01095d2c[];  // NiFloatsExtraDataPoint3Controller
void FUN_00a4ecd0();
extern const char DAT_01095d14[];  // NiGeomMorpherController
void FUN_00a3b550();
extern const char DAT_01095cfc[];  // NiKeyframeController
void FUN_00a36810();
extern const char DAT_01095cec[];  // NiKeyframeData
void FUN_00a4e040();
extern const char DAT_01095cd8[];  // NiKeyframeManager
void FUN_00a4db60();
extern const char DAT_01095cc0[];  // NiLightColorController
void FUN_00a4d500();
extern const char DAT_01095ca8[];  // NiLightDimmerController
void FUN_00a4d0d0();
extern const char DAT_01095c94[];  // NiLookAtController
void CreateMorphData();
extern const char DAT_01095c7c[];  // NiLookAtInterpolator
void FUN_00a4c5a0();
extern const char DAT_01095c60[];  // NiMaterialColorController
void FUN_00a4b790();
extern const char DAT_01095c54[];  // NiMorphData
void CreateA51BF0();
extern const char DAT_01095c30[];  // NiMultiTargetTransformController
void CreateCtl();
extern const char DAT_01095c1c[];  // NiPathController
void FUN_00a4b270();
extern const char DAT_01095c08[];  // NiPathInterpolator
void CreateA51BF0Base();
extern const char DAT_01095bf0[];  // NiPoint3Interpolator
void FUN_00a49a30();
extern const char DAT_01095be4[];  // NiPosData
void FUN_00a49020();
extern const char DAT_01095bc8[];  // NiQuaternionInterpolator
void CreateNiQuaternionInterpolator();
extern const char DAT_01095bb4[];  // NiRollController
void FUN_00a48750();
extern const char DAT_01095ba8[];  // NiRotData
void FUN_00a48110();
extern const char DAT_01095b9c[];  // NiSequence
void FUN_00a47f20();
extern const char DAT_01095b84[];  // NiSequenceStreamHelper
void FUN_00a47380();
extern const char DAT_01095b74[];  // NiStringPalette
void FUN_00a47150();
extern const char DAT_01095b60[];  // NiTextKeyExtraData
void FUN_00a46b70();
extern const char DAT_01095b40[];  // NiTextureTransformController
void FUN_00a46950();
extern const char DAT_01095b28[];  // NiTransformController
void FUN_00a36810();
extern const char DAT_01095b18[];  // NiTransformData
void FUN_00a4e040();
extern const char DAT_01095b00[];  // NiTransformInterpolator
void FUN_00a403f0();
extern const char DAT_01095af0[];  // NiUVController
void FUN_00a45f50();
extern const char DAT_01095ae4[];  // NiUVData
void CreateControllerAllocation();
extern const char DAT_01095ad4[];  // NiVisController
void FUN_00a44f10();
extern const char DAT_01095ac8[];  // BSAnimNotes
void FUN_00a44940();
extern const char DAT_01095ab8[];  // BSGrabIKNote
void FUN_00a44380();
extern const char DAT_01095aa8[];  // BSLookIKNote
void CreateLookIKNote();
extern const char DAT_01095a88[];  // BSRotAccumTransfInterpolator
void CreateRotAccumTransfInterpolator();
extern const char DAT_01095a6c[];  // BSTreadTransfInterpolator
void CreateDerivedA43370();
extern const char DAT_01095a4c[];  // BSBlendTreadTransfInterpolator
void FUN_00a42f90();
extern const char DAT_01095a28[];  // BSMultiTargetTreadTransfController
void FUN_00a359d0();
extern const char DAT_01095a10[];  // BSFrustumFOVController
void FUN_00a42ee0();
extern const char DAT_01095a04[];  // NiVisData
void FUN_00a537f0();
// @fnv 0x00a2d8a0
void FUN_00a2d8a0()
{
    if (!DAT_011f369d)
    {
        DAT_011f369d = true;
        FUN_00a64900(DAT_01096060, CreateFloatInterpController);
        FUN_00a64900(DAT_0109603c, FUN_00a39700);
        FUN_00a64900(DAT_01096024, FUN_00a565c0);
        FUN_00a64900(DAT_01096008, CreateBlendColorInterpolator);
        FUN_00a64900(DAT_01095fec, CreateNiBlendFloatInterpolator);
        FUN_00a64900(DAT_01095fd0, FUN_00a55a80);
        FUN_00a64900(DAT_01095fb0, FUN_00a55470);
        FUN_00a64900(DAT_01095f90, FUN_00a409d0);
        FUN_00a64900(DAT_01095f7c, CreateBoneLODController);
        FUN_00a64900(DAT_01095f70, FUN_00a537f0);
        FUN_00a64900(DAT_01095f5c, CreateNiKeyBasedInterpolator);
        FUN_00a64900(DAT_01095f40, CreateBoolInterpolator);
        FUN_00a64900(DAT_01095f2c, CreateNiSplineImpl);
        FUN_00a64900(DAT_01095f1c, FUN_00a51e10);
        FUN_00a64900(DAT_01095f00, FUN_00a51c60);
        FUN_00a64900(DAT_01095ee0, CreateSplineCompColorInterpolator);
        FUN_00a64900(DAT_01095ec0, FUN_00a51620);
        FUN_00a64900(DAT_01095ea0, CreateComp4);
        FUN_00a64900(DAT_01095e7c, CreateEvaluator);
        FUN_00a64900(DAT_01095e60, FUN_00a50ad0);
        FUN_00a64900(DAT_01095e44, FUN_00a50840);
        FUN_00a64900(DAT_01095e24, FUN_00a50180);
        FUN_00a64900(DAT_01095e18, CreateNiColorData);
        FUN_00a64900(DAT_01095dfc, FUN_00a4fac0);
        FUN_00a64900(DAT_01095de8, FUN_00a3c130);
        FUN_00a64900(DAT_01095dd4, FUN_00a2f6c0);
        FUN_00a64900(DAT_01095dbc, FUN_00a326c0);
        FUN_00a64900(DAT_01095da8, CreateNiFlipController);
        FUN_00a64900(DAT_01095d9c, CreateNiFloatData);
        FUN_00a64900(DAT_01095d80, FUN_00a411f0);
        FUN_00a64900(DAT_01095d6c, CreateNiFloatInterpolator);
        FUN_00a64900(DAT_01095d50, FUN_00a4f000);
        FUN_00a64900(DAT_01095d2c, FUN_00a4ecd0);
        FUN_00a64900(DAT_01095d14, FUN_00a3b550);
        FUN_00a64900(DAT_01095cfc, FUN_00a36810);
        FUN_00a64900(DAT_01095cec, FUN_00a4e040);
        FUN_00a64900(DAT_01095cd8, FUN_00a4db60);
        FUN_00a64900(DAT_01095cc0, FUN_00a4d500);
        FUN_00a64900(DAT_01095ca8, FUN_00a4d0d0);
        FUN_00a64900(DAT_01095c94, CreateMorphData);
        FUN_00a64900(DAT_01095c7c, FUN_00a4c5a0);
        FUN_00a64900(DAT_01095c60, FUN_00a4b790);
        FUN_00a64900(DAT_01095c54, CreateA51BF0);
        FUN_00a64900(DAT_01095c30, CreateCtl);
        FUN_00a64900(DAT_01095c1c, FUN_00a4b270);
        FUN_00a64900(DAT_01095c08, CreateA51BF0Base);
        FUN_00a64900(DAT_01095bf0, FUN_00a49a30);
        FUN_00a64900(DAT_01095be4, FUN_00a49020);
        FUN_00a64900(DAT_01095bc8, CreateNiQuaternionInterpolator);
        FUN_00a64900(DAT_01095bb4, FUN_00a48750);
        FUN_00a64900(DAT_01095ba8, FUN_00a48110);
        FUN_00a64900(DAT_01095b9c, FUN_00a47f20);
        FUN_00a64900(DAT_01095b84, FUN_00a47380);
        FUN_00a64900(DAT_01095b74, FUN_00a47150);
        FUN_00a64900(DAT_01095b60, FUN_00a46b70);
        FUN_00a64900(DAT_01095b40, FUN_00a46950);
        FUN_00a64900(DAT_01095b28, FUN_00a36810);
        FUN_00a64900(DAT_01095b18, FUN_00a4e040);
        FUN_00a64900(DAT_01095b00, FUN_00a403f0);
        FUN_00a64900(DAT_01095af0, FUN_00a45f50);
        FUN_00a64900(DAT_01095ae4, CreateControllerAllocation);
        FUN_00a64900(DAT_01095ad4, FUN_00a44f10);
        FUN_00a64900(DAT_01095ac8, FUN_00a44940);
        FUN_00a64900(DAT_01095ab8, FUN_00a44380);
        FUN_00a64900(DAT_01095aa8, CreateLookIKNote);
        FUN_00a64900(DAT_01095a88, CreateRotAccumTransfInterpolator);
        FUN_00a64900(DAT_01095a6c, CreateDerivedA43370);
        FUN_00a64900(DAT_01095a4c, FUN_00a42f90);
        FUN_00a64900(DAT_01095a28, FUN_00a359d0);
        FUN_00a64900(DAT_01095a10, FUN_00a42ee0);
        FUN_00a64900(DAT_01095a04, FUN_00a537f0);
        FUN_00a64920(FUN_00a42c80);
        FUN_00a421c0();
    }
}
