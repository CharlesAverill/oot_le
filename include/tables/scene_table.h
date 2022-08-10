/**
 * Scene Table
 *
 * DEFINE_SCENE should be used for all scenes (with or without a title card, see argument 2)
 *    - Argument 1: Name of the scene segment in spec
 *    - Argument 2: Name of the title card segment in spec, or `none` for no title card
 *    - Argument 3: Enum value for this scene
 *    - Argument 4: Scene draw config index
 *    - Argument 5: ? (Unknown)
 *    - Argument 6: ? (Unknown)
 */
/* 0x00 */ DEFINE_SCENE(ydan_scene, g_pn_06, SCENE_YDAN, SDC_YDAN, 1, 2)
/* 0x01 */ DEFINE_SCENE(ddan_scene, g_pn_08, SCENE_DDAN, SDC_DDAN, 1, 3)
/* 0x02 */ DEFINE_SCENE(bdan_scene, g_pn_07, SCENE_BDAN, SDC_BDAN, 1, 4)
/* 0x03 */ DEFINE_SCENE(Bmori1_scene, g_pn_01, SCENE_BMORI1, SDC_BMORI1, 2, 5)
/* 0x04 */ DEFINE_SCENE(HIDAN_scene, g_pn_03, SCENE_HIDAN, SDC_HIDAN, 2, 6)
/* 0x05 */ DEFINE_SCENE(MIZUsin_scene, g_pn_04, SCENE_MIZUSIN, SDC_MIZUSIN, 1, 7)
/* 0x06 */ DEFINE_SCENE(jyasinzou_scene, g_pn_05, SCENE_JYASINZOU, SDC_JYASINZOU, 1, 8)
/* 0x07 */ DEFINE_SCENE(HAKAdan_scene, g_pn_02, SCENE_HAKADAN, SDC_HAKADAN, 2, 9)
/* 0x08 */ DEFINE_SCENE(HAKAdanCH_scene, g_pn_54, SCENE_HAKADANCH, SDC_HAKADAN, 2, 10)
/* 0x09 */ DEFINE_SCENE(ice_doukutu_scene, g_pn_10, SCENE_ICE_DOUKUTO, SDC_ICE_DOUKUTO, 0, 0)
/* 0x0A */ DEFINE_SCENE(ganon_scene, none, SCENE_GANON, SDC_DEFAULT, 2, 0)
/* 0x0B */ DEFINE_SCENE(men_scene, g_pn_11, SCENE_MEN, SDC_MEN, 0, 0)
/* 0x0C */ DEFINE_SCENE(gerudoway_scene, g_pn_49, SCENE_GERUDOWAY, SDC_GERUDOWAY, 0, 0)
/* 0x0D */ DEFINE_SCENE(ganontika_scene, g_pn_09, SCENE_GANONTIKA, SDC_GANONTIKA, 0, 0)
/* 0x0E */ DEFINE_SCENE(ganon_sonogo_scene, none, SCENE_GANON_SONOGO, SDC_GANON_SONOGO, 0, 0)
/* 0x0F */ DEFINE_SCENE(ganontikasonogo_scene, none, SCENE_GANONTIKA_SONOGO, SDC_GANONTIKA_SONOGO, 0, 0)
/* 0x10 */ DEFINE_SCENE(takaraya_scene, g_pn_51, SCENE_TAKARAYA, SDC_DEFAULT, 0, 0)
/* 0x11 */ DEFINE_SCENE(ydan_boss_scene, none, SCENE_YDAN_BOSS, SDC_YDAN_BOSS, 0, 0)
/* 0x12 */ DEFINE_SCENE(ddan_boss_scene, none, SCENE_DDAN_BOSS, SDC_DEFAULT, 0, 0)
/* 0x13 */ DEFINE_SCENE(bdan_boss_scene, none, SCENE_BDAN_BOSS, SDC_BDAN, 0, 0)
/* 0x14 */ DEFINE_SCENE(moribossroom_scene, none, SCENE_MORIBOSSROOM, SDC_DEFAULT, 1, 0)
/* 0x15 */ DEFINE_SCENE(FIRE_bs_scene, none, SCENE_FIRE_BS, SDC_HIDAN, 0, 0)
/* 0x16 */ DEFINE_SCENE(MIZUsin_bs_scene, none, SCENE_MIZUSIN_BS, SDC_MIZUSIN_BS, 0, 0)
/* 0x17 */ DEFINE_SCENE(jyasinboss_scene, none, SCENE_JYASINBOSS, SDC_DEFAULT, 0, 0)
/* 0x18 */ DEFINE_SCENE(HAKAdan_bs_scene, none, SCENE_HAKADAN_BS, SDC_HAKADAN, 0, 0)
/* 0x19 */ DEFINE_SCENE(ganon_boss_scene, none, SCENE_GANON_BOSS, SDC_DEFAULT, 0, 0)
/* 0x1A */ DEFINE_SCENE(ganon_final_scene, none, SCENE_GANON_FINAL, SDC_GANON_FINAL, 0, 0)
/* 0x1B */ DEFINE_SCENE(entra_scene, none, SCENE_ENTRA, SDC_DEFAULT, 0, 0)
/* 0x1C */ DEFINE_SCENE(entra_n_scene, none, SCENE_ENTRA_N, SDC_DEFAULT, 0, 0)
/* 0x1D */ DEFINE_SCENE(enrui_scene, none, SCENE_ENRUI, SDC_DEFAULT, 0, 0)
/* 0x1E */ DEFINE_SCENE(market_alley_scene, g_pn_18, SCENE_MARKET_ALLEY, SDC_DEFAULT, 0, 0)
/* 0x1F */ DEFINE_SCENE(market_alley_n_scene, g_pn_18, SCENE_MARKET_ALLEY_N, SDC_DEFAULT, 0, 0)
/* 0x20 */ DEFINE_SCENE(market_day_scene, g_pn_17, SCENE_MARKET_DAY, SDC_DEFAULT, 0, 0)
/* 0x21 */ DEFINE_SCENE(market_night_scene, g_pn_17, SCENE_MARKET_NIGHT, SDC_DEFAULT, 0, 0)
/* 0x22 */ DEFINE_SCENE(market_ruins_scene, g_pn_17, SCENE_MARKET_RUINS, SDC_DEFAULT, 0, 0)
/* 0x23 */ DEFINE_SCENE(shrine_scene, none, SCENE_SHRINE, SDC_DEFAULT, 0, 0)
/* 0x24 */ DEFINE_SCENE(shrine_n_scene, none, SCENE_SHRINE_N, SDC_DEFAULT, 0, 0)
/* 0x25 */ DEFINE_SCENE(shrine_r_scene, none, SCENE_SHRINE_R, SDC_DEFAULT, 0, 0)
/* 0x26 */ DEFINE_SCENE(kokiri_home_scene, none, SCENE_KOKIRI_HOME, SDC_DEFAULT, 0, 0)
/* 0x27 */ DEFINE_SCENE(kokiri_home3_scene, none, SCENE_KOKIRI_HOME3, SDC_DEFAULT, 0, 0)
/* 0x28 */ DEFINE_SCENE(kokiri_home4_scene, none, SCENE_KOKIRI_HOME4, SDC_DEFAULT, 0, 0)
/* 0x29 */ DEFINE_SCENE(kokiri_home5_scene, none, SCENE_KOKIRI_HOME5, SDC_DEFAULT, 0, 0)
/* 0x2A */ DEFINE_SCENE(kakariko_scene, none, SCENE_KAKARIKO, SDC_DEFAULT, 0, 0)
/* 0x2B */ DEFINE_SCENE(kakariko3_scene, none, SCENE_KAKARIKO3, SDC_DEFAULT, 0, 0)
/* 0x2C */ DEFINE_SCENE(shop1_scene, g_pn_23, SCENE_SHOP1, SDC_DEFAULT, 0, 0)
/* 0x2D */ DEFINE_SCENE(kokiri_shop_scene, g_pn_19, SCENE_KOKIRI_SHOP, SDC_DEFAULT, 0, 0)
/* 0x2E */ DEFINE_SCENE(golon_scene, g_pn_20, SCENE_GOLON, SDC_DEFAULT, 0, 0)
/* 0x2F */ DEFINE_SCENE(zoora_scene, g_pn_21, SCENE_ZOORA, SDC_DEFAULT, 0, 0)
/* 0x30 */ DEFINE_SCENE(drag_scene, g_pn_24, SCENE_DRAG, SDC_DEFAULT, 0, 0)
/* 0x31 */ DEFINE_SCENE(alley_shop_scene, g_pn_24, SCENE_ALLEY_SHOP, SDC_DEFAULT, 0, 0)
/* 0x32 */ DEFINE_SCENE(night_shop_scene, g_pn_56, SCENE_NIGHT_SHOP, SDC_DEFAULT, 0, 0)
/* 0x33 */ DEFINE_SCENE(face_shop_scene, g_pn_50, SCENE_FACE_SHOP, SDC_DEFAULT, 0, 0)
/* 0x34 */ DEFINE_SCENE(link_home_scene, none, SCENE_LINK_HOME, SDC_DEFAULT, 0, 0)
/* 0x35 */ DEFINE_SCENE(impa_scene, none, SCENE_IMPA, SDC_DEFAULT, 0, 0)
/* 0x36 */ DEFINE_SCENE(malon_stable_scene, g_pn_48, SCENE_MALON_STABLE, SDC_DEFAULT, 0, 0)
/* 0x37 */ DEFINE_SCENE(labo_scene, none, SCENE_LABO, SDC_DEFAULT, 0, 0)
/* 0x38 */ DEFINE_SCENE(hylia_labo_scene, g_pn_26, SCENE_HYLIA_LABO, SDC_HYLIA_LABO, 0, 0)
/* 0x39 */ DEFINE_SCENE(tent_scene, none, SCENE_TENT, SDC_DEFAULT, 0, 0)
/* 0x3A */ DEFINE_SCENE(hut_scene, g_pn_25, SCENE_HUT, SDC_DEFAULT, 0, 0)
/* 0x3B */ DEFINE_SCENE(daiyousei_izumi_scene, g_pn_13, SCENE_DAIYOUSEI_IZUMI, SDC_GREAT_FAIRY_FOUNTAIN, 0, 0)
/* 0x3C */ DEFINE_SCENE(yousei_izumi_tate_scene, g_pn_45, SCENE_YOUSEI_IZUMI_TATE, SDC_FAIRY_FOUNTAIN, 0, 0)
/* 0x3D */ DEFINE_SCENE(yousei_izumi_yoko_scene, g_pn_13, SCENE_YOUSEI_IZUMI_YOKO, SDC_GREAT_FAIRY_FOUNTAIN, 0, 0)
/* 0x3E */ DEFINE_SCENE(kakusiana_scene, none, SCENE_KAKUSIANA, SDC_KAKUSIANA, 0, 0)
/* 0x3F */ DEFINE_SCENE(hakaana_scene, none, SCENE_HAKAANA, SDC_GRAVE_EXIT_LIGHT_SHINING, 0, 0)
/* 0x40 */ DEFINE_SCENE(hakaana2_scene, none, SCENE_HAKAANA2, SDC_FAIRY_FOUNTAIN, 0, 0)
/* 0x41 */ DEFINE_SCENE(hakaana_ouke_scene, g_pn_44, SCENE_HAKAANA_OUKE, SDC_HAKAANA_OUKE, 0, 0)
/* 0x42 */ DEFINE_SCENE(syatekijyou_scene, g_pn_15, SCENE_SYATEKIJYOU, SDC_SYATEKIJYOU, 0, 0)
/* 0x43 */ DEFINE_SCENE(tokinoma_scene, g_pn_16, SCENE_TOKINOMA, SDC_TOKINOMA, 0, 0)
/* 0x44 */ DEFINE_SCENE(kenjyanoma_scene, g_pn_14, SCENE_KENJYANOMA, SDC_KENJYANOMA, 0, 0)
/* 0x45 */ DEFINE_SCENE(hairal_niwa_scene, g_pn_12, SCENE_HAIRAL_NIWA, SDC_HAIRAL_NIWA, 0, 0)
/* 0x46 */ DEFINE_SCENE(hairal_niwa_n_scene, g_pn_12, SCENE_HAIRAL_NIWA_N, SDC_HAIRAL_NIWA, 0, 0)
/* 0x47 */ DEFINE_SCENE(hiral_demo_scene, none, SCENE_HIRAL_DEMO, SDC_DEFAULT, 0, 0)
/* 0x48 */ DEFINE_SCENE(hakasitarelay_scene, g_pn_57, SCENE_HAKASITARELAY, SDC_GRAVE_EXIT_LIGHT_SHINING, 0, 0)
/* 0x49 */ DEFINE_SCENE(turibori_scene, g_pn_46, SCENE_TURIBORI, SDC_TURIBORI, 0, 0)
/* 0x4A */ DEFINE_SCENE(nakaniwa_scene, g_pn_12, SCENE_NAKANIWA, SDC_CALM_WATER, 0, 0)
/* 0x4B */ DEFINE_SCENE(bowling_scene, g_pn_47, SCENE_BOWLING, SDC_BOWLING, 0, 0)
/* 0x4C */ DEFINE_SCENE(souko_scene, none, SCENE_SOUKO, SDC_SOUKO, 0, 0)
/* 0x4D */ DEFINE_SCENE(miharigoya_scene, none, SCENE_MIHARIGOYA, SDC_MIHARIGOYA, 0, 0)
/* 0x4E */ DEFINE_SCENE(mahouya_scene, g_pn_24, SCENE_MAHOUYA, SDC_MAHOUYA, 0, 0)
/* 0x4F */ DEFINE_SCENE(ganon_demo_scene, none, SCENE_GANON_DEMO, SDC_GANON_CASTLE_EXTERIOR, 0, 0)
/* 0x50 */ DEFINE_SCENE(kinsuta_scene, g_pn_22, SCENE_KINSUTA, SDC_DEFAULT, 0, 0)
/* 0x51 */ DEFINE_SCENE(spot00_scene, g_pn_27, SCENE_SPOT00, SDC_SPOT00, 0, 0)
/* 0x52 */ DEFINE_SCENE(spot01_scene, g_pn_28, SCENE_SPOT01, SDC_SPOT01, 0, 0)
/* 0x53 */ DEFINE_SCENE(spot02_scene, g_pn_29, SCENE_SPOT02, SDC_DEFAULT, 0, 0)
/* 0x54 */ DEFINE_SCENE(spot03_scene, g_pn_30, SCENE_SPOT03, SDC_SPOT03, 0, 0)
/* 0x55 */ DEFINE_SCENE(spot04_scene, g_pn_31, SCENE_SPOT04, SDC_SPOT04, 0, 0)
/* 0x56 */ DEFINE_SCENE(spot05_scene, g_pn_52, SCENE_SPOT05, SDC_CALM_WATER, 0, 0)
/* 0x57 */ DEFINE_SCENE(spot06_scene, g_pn_32, SCENE_SPOT06, SDC_SPOT06, 0, 0)
/* 0x58 */ DEFINE_SCENE(spot07_scene, g_pn_33, SCENE_SPOT07, SDC_SPOT07, 0, 0)
/* 0x59 */ DEFINE_SCENE(spot08_scene, g_pn_34, SCENE_SPOT08, SDC_SPOT08, 0, 0)
/* 0x5A */ DEFINE_SCENE(spot09_scene, g_pn_35, SCENE_SPOT09, SDC_SPOT09, 0, 0)
/* 0x5B */ DEFINE_SCENE(spot10_scene, g_pn_36, SCENE_SPOT10, SDC_SPOT10, 0, 0)
/* 0x5C */ DEFINE_SCENE(spot11_scene, g_pn_55, SCENE_SPOT11, SDC_SPOT11, 0, 0)
/* 0x5D */ DEFINE_SCENE(spot12_scene, g_pn_53, SCENE_SPOT12, SDC_SPOT12, 0, 0)
/* 0x5E */ DEFINE_SCENE(spot13_scene, g_pn_37, SCENE_SPOT13, SDC_SPOT13, 0, 0)
/* 0x5F */ DEFINE_SCENE(spot15_scene, g_pn_38, SCENE_SPOT15, SDC_SPOT15, 0, 0)
/* 0x60 */ DEFINE_SCENE(spot16_scene, g_pn_39, SCENE_SPOT16, SDC_SPOT16, 0, 0)
/* 0x61 */ DEFINE_SCENE(spot17_scene, g_pn_40, SCENE_SPOT17, SDC_SPOT17, 0, 0)
/* 0x62 */ DEFINE_SCENE(spot18_scene, g_pn_41, SCENE_SPOT18, SDC_SPOT18, 0, 0)
/* 0x63 */ DEFINE_SCENE(spot20_scene, g_pn_42, SCENE_SPOT20, SDC_SPOT20, 0, 0)
/* 0x64 */ DEFINE_SCENE(ganon_tou_scene, g_pn_43, SCENE_GANON_TOU, SDC_GANON_CASTLE_EXTERIOR, 0, 0)
// Debug-only scenes
/* 0x65 */ DEFINE_SCENE(test01_scene, none, SCENE_TEST01, SDC_CALM_WATER, 0, 0)
/* 0x66 */ DEFINE_SCENE(besitu_scene, none, SCENE_BESITU, SDC_BESITU, 0, 0)
/* 0x67 */ DEFINE_SCENE(depth_test_scene, none, SCENE_DEPTH_TEST, SDC_DEFAULT, 0, 0)
/* 0x68 */ DEFINE_SCENE(syotes_scene, none, SCENE_SYOTES, SDC_DEFAULT, 0, 0)
/* 0x69 */ DEFINE_SCENE(syotes2_scene, none, SCENE_SYOTES2, SDC_DEFAULT, 0, 0)
/* 0x6A */ DEFINE_SCENE(sutaru_scene, none, SCENE_SUTARU, SDC_DEFAULT, 0, 0)
/* 0x6B */ DEFINE_SCENE(hairal_niwa2_scene, g_pn_12, SCENE_HAIRAL_NIWA2, SDC_HAIRAL_NIWA, 0, 0)
/* 0x6C */ DEFINE_SCENE(sasatest_scene, none, SCENE_SASATEST, SDC_DEFAULT, 0, 0)
/* 0x6D */ DEFINE_SCENE(testroom_scene, none, SCENE_TESTROOM, SDC_DEFAULT, 0, 0)
// Added scenes
/* 0x6E */ DEFINE_SCENE(learning01_scene, none, SCENE_LEARNING01, SDC_DEFAULT, 0, 0)
/* 0x6F */ DEFINE_SCENE(newmarket_scene, none, SCENE_NEWMARKET, SDC_DEFAULT, 0, 0)
