
// src/gamebryo2.2/corelibs/niparticle/niparticlesdm.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/niparticlesdm.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl FUN_00a63520(const char* pName);
void __cdecl DestroyManager();
extern bool g_bInitialized_012024d0;

static const char s_sz00[] = "NiMeshParticleSystem";
static const char s_sz01[] = "NiMeshPSysData";
static const char s_sz02[] = "NiParticleSystem";
static const char s_sz03[] = "NiPSysAirFieldAirFrictionCtlr";
static const char s_sz04[] = "NiPSysAirFieldInheritVelocityCtlr";
static const char s_sz05[] = "NiPSysAirFieldModifier";
static const char s_sz06[] = "NiPSysAirFieldSpreadCtlr";
static const char s_sz07[] = "NiPSysAgeDeathModifier";
static const char s_sz08[] = "NiPSysBombModifier";
static const char s_sz09[] = "NiPSysBoundUpdateModifier";
static const char s_sz10[] = "NiPSysBoxEmitter";
static const char s_sz11[] = "NiPSysColliderManager";
static const char s_sz12[] = "NiPSysColorModifier";
static const char s_sz13[] = "NiPSysCylinderEmitter";
static const char s_sz14[] = "NiPSysData";
static const char s_sz15[] = "NiPSysDragFieldModifier";
static const char s_sz16[] = "NiPSysDragModifier";
static const char s_sz17[] = "NiPSysEmitterCtlr";
static const char s_sz18[] = "NiPSysEmitterCtlrData";
static const char s_sz19[] = "NiPSysEmitterDeclinationCtlr";
static const char s_sz20[] = "NiPSysEmitterDeclinationVarCtlr";
static const char s_sz21[] = "NiPSysEmitterInitialRadiusCtlr";
static const char s_sz22[] = "NiPSysEmitterLifeSpanCtlr";
static const char s_sz23[] = "NiPSysEmitterPlanarAngleCtlr";
static const char s_sz24[] = "NiPSysEmitterPlanarAngleVarCtlr";
static const char s_sz25[] = "NiPSysEmitterSpeedCtlr";
static const char s_sz26[] = "NiPSysFieldAttenuationCtlr";
static const char s_sz27[] = "NiPSysFieldMagnitudeCtlr";
static const char s_sz28[] = "NiPSysFieldMaxDistanceCtlr";
static const char s_sz29[] = "NiPSysGravityModifier";
static const char s_sz30[] = "NiPSysGravityFieldModifier";
static const char s_sz31[] = "NiPSysGravityStrengthCtlr";
static const char s_sz32[] = "NiPSysGrowFadeModifier";
static const char s_sz33[] = "NiPSysInitialRotAngleCtlr";
static const char s_sz34[] = "NiPSysInitialRotAngleVarCtlr";
static const char s_sz35[] = "NiPSysInitialRotSpeedCtlr";
static const char s_sz36[] = "NiPSysInitialRotSpeedVarCtlr";
static const char s_sz37[] = "NiPSysMeshEmitter";
static const char s_sz38[] = "NiPSysMeshUpdateModifier";
static const char s_sz39[] = "NiPSysModifierActiveCtlr";
static const char s_sz40[] = "NiPSysPlanarCollider";
static const char s_sz41[] = "NiPSysPositionModifier";
static const char s_sz42[] = "NiPSysRadialFieldModifier";
static const char s_sz43[] = "NiPSysResetOnLoopCtlr";
static const char s_sz44[] = "NiPSysRotationModifier";
static const char s_sz45[] = "NiPSysSpawnModifier";
static const char s_sz46[] = "NiPSysSphereEmitter";
static const char s_sz47[] = "NiPSysSphericalCollider";
static const char s_sz48[] = "NiPSysTurbulenceFieldModifier";
static const char s_sz49[] = "NiPSysUpdateCtlr";
static const char s_sz50[] = "NiPSysVortexFieldModifier";
__declspec(selectany) extern const char g_szShutdownEnd[] = "";

// @fnv 0x00c1a7d0
void __cdecl FUN_00c1a7d0()
{
    if (!g_bInitialized_012024d0)
        return;
    g_bInitialized_012024d0 = false;
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
    DestroyManager();
}

#include <windows.h>
typedef void* (*S_00c1aa00_CreateFunc)();
void FUN_00a64900(const char* pcName, S_00c1aa00_CreateFunc pfnCreate);

void* FUN_00c21e90();
void* CreateNiMeshPSysData();
void* FUN_00c1b7f0();
void* FUN_00c30790();
void* FUN_00c30600();
void* CreateAirTmp();
void* FUN_00c2f3a0();
void* FUN_00c2ef20();
void* FUN_00c2e4c0();
void* CreateNiPSysModC2D();
void* FUN_00c20350();
void* FUN_00c2d5b0();
void* CreateColorModifier();
void* FUN_00c1fbf0();
void* FUN_00c24da0();
void* FUN_00c2c7b0();
void* FUN_00c2c080();
void* CreateNiPSysEmitterCtlrC1C5();
void* FUN_00c2ba60();
void* FUN_00c2b970();
void* FUN_00c2b870();
void* FUN_00c2b720();
void* FUN_00c2b620();
void* CreatePSysFactoryObjectB52();
void* CreatePSysFactoryObject();
void* CreateParticleEmitterAllocation();
void* FUN_00c2b200();
void* FUN_00c2b110();
void* FUN_00c2b010();
void* FUN_00c22ad0();
void* CreateGravityFieldModifier();
void* FUN_00c2a870();
void* FUN_00c2a2b0();
void* CreateParticleObjectFactory();
void* FUN_00c2a050();
void* CreateParticleFactoryObject();
void* CreateC29E50Object();
void* CreateNiPSysMeshEmitterObject();
void* CreateModifier();
void* FUN_00c29d00();
void* FUN_00c29af0();
void* FUN_00c28b20();
void* FUN_00c28570();
void* FUN_00c283b0();
void* FUN_00c20640();
void* FUN_00c23b20();
void* FUN_00c1fff0();
void* CreateCollider();
void* FUN_00c27350();
void* FUN_00c270f0();
void* FUN_00c26790();
void* FUN_00c25820();
void* CreateFUN_00c24c90();

bool DAT_012024d0;
DWORD DAT_012024dc;

// Registers particle system class factories with FUN_00a64900 and stores the calling thread ID in DAT_012024dc.
// @fnv 0x00c1aa00
void RegisterParticleSystems()
{
    if (DAT_012024d0)
        return;
    DAT_012024d0 = true;

    FUN_00a64900("NiMeshParticleSystem", FUN_00c21e90);
    FUN_00a64900("NiMeshPSysData", CreateNiMeshPSysData);
    FUN_00a64900("NiParticleSystem", FUN_00c1b7f0);
    FUN_00a64900("NiPSysAirFieldAirFrictionCtlr", FUN_00c30790);
    FUN_00a64900("NiPSysAirFieldInheritVelocityCtlr", FUN_00c30600);
    FUN_00a64900("NiPSysAirFieldModifier", CreateAirTmp);
    FUN_00a64900("NiPSysAirFieldSpreadCtlr", FUN_00c2f3a0);
    FUN_00a64900("NiPSysAgeDeathModifier", FUN_00c2ef20);
    FUN_00a64900("NiPSysBombModifier", FUN_00c2e4c0);
    FUN_00a64900("NiPSysBoundUpdateModifier", CreateNiPSysModC2D);
    FUN_00a64900("NiPSysBoxEmitter", FUN_00c20350);
    FUN_00a64900("NiPSysColliderManager", FUN_00c2d5b0);
    FUN_00a64900("NiPSysColorModifier", CreateColorModifier);
    FUN_00a64900("NiPSysCylinderEmitter", FUN_00c1fbf0);
    FUN_00a64900("NiPSysData", FUN_00c24da0);
    FUN_00a64900("NiPSysDragFieldModifier", FUN_00c2c7b0);
    FUN_00a64900("NiPSysDragModifier", FUN_00c2c080);
    FUN_00a64900("NiPSysEmitterCtlr", CreateNiPSysEmitterCtlrC1C5);
    FUN_00a64900("NiPSysEmitterCtlrData", FUN_00c2ba60);
    FUN_00a64900("NiPSysEmitterDeclinationCtlr", FUN_00c2b970);
    FUN_00a64900("NiPSysEmitterDeclinationVarCtlr", FUN_00c2b870);
    FUN_00a64900("NiPSysEmitterInitialRadiusCtlr", FUN_00c2b720);
    FUN_00a64900("NiPSysEmitterLifeSpanCtlr", FUN_00c2b620);
    FUN_00a64900("NiPSysEmitterPlanarAngleCtlr", CreatePSysFactoryObjectB52);
    FUN_00a64900("NiPSysEmitterPlanarAngleVarCtlr", CreatePSysFactoryObject);
    FUN_00a64900("NiPSysEmitterSpeedCtlr", CreateParticleEmitterAllocation);
    FUN_00a64900("NiPSysFieldAttenuationCtlr", FUN_00c2b200);
    FUN_00a64900("NiPSysFieldMagnitudeCtlr", FUN_00c2b110);
    FUN_00a64900("NiPSysFieldMaxDistanceCtlr", FUN_00c2b010);
    FUN_00a64900("NiPSysGravityModifier", FUN_00c22ad0);
    FUN_00a64900("NiPSysGravityFieldModifier", CreateGravityFieldModifier);
    FUN_00a64900("NiPSysGravityStrengthCtlr", FUN_00c2a870);
    FUN_00a64900("NiPSysGrowFadeModifier", FUN_00c2a2b0);
    FUN_00a64900("NiPSysInitialRotAngleCtlr", CreateParticleObjectFactory);
    FUN_00a64900("NiPSysInitialRotAngleVarCtlr", FUN_00c2a050);
    FUN_00a64900("NiPSysInitialRotSpeedCtlr", CreateParticleFactoryObject);
    FUN_00a64900("NiPSysInitialRotSpeedVarCtlr", CreateC29E50Object);
    FUN_00a64900("NiPSysMeshEmitter", CreateNiPSysMeshEmitterObject);
    FUN_00a64900("NiPSysMeshUpdateModifier", CreateModifier);
    FUN_00a64900("NiPSysModifierActiveCtlr", FUN_00c29d00);
    FUN_00a64900("NiPSysPlanarCollider", FUN_00c29af0);
    FUN_00a64900("NiPSysPositionModifier", FUN_00c28b20);
    FUN_00a64900("NiPSysRadialFieldModifier", FUN_00c28570);
    FUN_00a64900("NiPSysResetOnLoopCtlr", FUN_00c283b0);
    FUN_00a64900("NiPSysRotationModifier", FUN_00c20640);
    FUN_00a64900("NiPSysSpawnModifier", FUN_00c23b20);
    FUN_00a64900("NiPSysSphereEmitter", FUN_00c1fff0);
    FUN_00a64900("NiPSysSphericalCollider", CreateCollider);
    FUN_00a64900("NiPSysTurbulenceFieldModifier", FUN_00c27350);
    FUN_00a64900("NiPSysUpdateCtlr", FUN_00c270f0);
    FUN_00a64900("NiPSysVortexFieldModifier", FUN_00c26790);
    FUN_00a64900("BSStripParticleSystem", FUN_00c25820);
    FUN_00a64900("BSStripPSysData", CreateFUN_00c24c90);

    DAT_012024dc = GetCurrentThreadId();
}
