static const u8 sWholeNewWorldAchLabel[] = _("A Whole New World");
static const u8 sWholeNewWorldAchDesc[] = _("Welcome to Emerald Enhanced.\nExplore to your heart's content!");

static const u8 sEnhancedBattleAchLabel[] = _("Enhanced Battle");
static const u8 sEnhancedBattleAchDesc[] = _("You have awakened as a battle master!");

static const u8 sNewRegionWhoDisAchLabel[] = _("New Region Who Dis");
static const u8 sNewRegionWhoDisAchDesc[] = _("You made a friend!\nEverything is better with friends.");

static const u8 sAdventureTimeAchLabel[] = _("Adventure Time");
static const u8 sAdventureTimeAchDesc[] = _("You started your first quest.\nGood Luck!");

static const u8 sTrueLoveAchLabel[] = _("Love at First Sight");
static const u8 sTrueLoveAchDesc[] = _("You have entered a relationship.\nNow you wonder what you would\ndo without them.");

static const u8 sSilentStrongTypeAchLabel[] = _("Silent, Strong type");
static const u8 sSilentStrongTypeAchDesc[] = _("The quiet ones usually have the\nmost to say!\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Romanced Lana)");

static const u8 sChildhoodFriendAchLabel[] = _("A Childhood Friend");
static const u8 sChildhoodFriendAchDesc[] = _("{RIVAL} would follow you off\nof a cliff.\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Romanced {RIVAL})");

static const u8 sNerdLoveAchLabel[] = _("Nerd Love");
static const u8 sNerdLoveAchDesc[] = _("You feel her rubbing off on you.\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Romanced Lanette)");

static const u8 sFWBAchLabel[] = _("Friends with Benefits");
static const u8 sFWBAchDesc[] = _("You have a secret weapon!\nYour own, personal nurse.\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Romanced Joy)");

static const u8 sWetnWildAchLabel[] = _("Wet and Wild");
static const u8 sWetnWildAchDesc[] = _("You found a girl who loves to\nget wet.\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Romanced Shelly)");

static const u8 sFieryPassionAchLabel[] = _("Fiery Passion");
static const u8 sFieryPassionAchDesc[] = _("She's blazing hot!\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Romanced Courtney)");

static const u8 sTrueEndingAchLabel[] = _("The True Ending");
static const u8 sTrueEndingAchDesc[] = _("You're quite the lady killer, eh?\n {COLOR LIGHT_GREEN}{SHADOW GREEN}(Got the Harem ending)");

static const struct AtlasAchPointData sAchAtlasData[] =
{
    {12, 55, CATEGORY_EXPLORATION, FLAG_ACH_WHOLE_NEW_WORLD, sWholeNewWorldAchLabel, sWholeNewWorldAchDesc},
    {28, 55, CATEGORY_BATTLE, FLAG_ACH_ENHANCED_BATTLE, sEnhancedBattleAchLabel, sEnhancedBattleAchDesc},
    {57, 55, CATEGORY_COMPANIONS, FLAG_ACH_NEW_REGION_WHO_DIS, sNewRegionWhoDisAchLabel, sNewRegionWhoDisAchDesc},
    {43, 55, CATEGORY_QUESTING, FLAG_ACH_ADVENTURE_TIME, sAdventureTimeAchLabel, sAdventureTimeAchLabel},
    {57, 52, CATEGORY_COMPANIONS, FLAG_ACH_TRUE_LOVE, sTrueLoveAchLabel, sTrueLoveAchDesc},
    {59, 48, CATEGORY_COMPANIONS, FLAG_ACH_SILENT_STRONG_TYPE, sSilentStrongTypeAchLabel, sSilentStrongTypeAchDesc},
    {59, 50, CATEGORY_COMPANIONS, FLAG_ACH_CHILDHOOD_FRIEND, sChildhoodFriendAchLabel, sChildhoodFriendAchDesc},
    {59, 52, CATEGORY_COMPANIONS, FLAG_ACH_FIERY_PASSION, sFieryPassionAchLabel, sFieryPassionAchDesc},
    {61, 48, CATEGORY_COMPANIONS, FLAG_ACH_NERD_LOVE, sNerdLoveAchLabel, sNerdLoveAchDesc},
    {61, 50, CATEGORY_COMPANIONS, FLAG_ACH_FWB, sFWBAchLabel, sFWBAchDesc},
    {61, 52, CATEGORY_COMPANIONS, FLAG_ACH_WET_N_WILD, sWetnWildAchLabel, sWetnWildAchDesc},
    {60, 46, CATEGORY_COMPANIONS, FLAG_ACH_TRUE_ENDING, sTrueEndingAchLabel, sTrueEndingAchDesc}, 
};