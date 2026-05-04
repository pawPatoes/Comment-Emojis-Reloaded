#pragma once
#include <AdvancedLabel.hpp>
#include "utils.hpp"

#include <Geode/binding/GJSearchObject.hpp>
#include <Geode/binding/LevelBrowserLayer.hpp>

constexpr char32_t MentionChar = 0x1c900;
constexpr std::u32string_view MentionCharStrView = { &MentionChar, 1 };
constexpr auto MentionCharStr = UTF32ToUTF8<MentionChar>::utf8_view;

constexpr auto EmojiGroups = std::tuple<
    EmojiGroup<
        "Geometry Dash", ":easy:",
        // Level difficulties
        Unimoji<"na", 0x1c000>,          Unimoji<"auto", 0x1c001>,
        Unimoji<"easy", 0x1c002>,        Unimoji<"normal", 0x1c003>,
        Unimoji<"hard", 0x1c004>,        Unimoji<"harder", 0x1c005>,
        Unimoji<"insane", 0x1c006>,      Unimoji<"easydemon", 0x1c007>,
        Unimoji<"mediumdemon", 0x1c008>, Unimoji<"harddemon", 0x1c009>,
        Unimoji<"insanedemon", 0x1c00a>, Unimoji<"extremedemon", 0x1c00b>,
        Unimoji<"casual", 0x1c00c>,      Unimoji<"tough", 0x1c00d>,
        Unimoji<"cruel", 0x1c00e>,       HiddenUnimoji<"creul", 0x1c00e>,
        // Currency
        Unimoji<"orb", 0x1c010>,     Unimoji<"orbs", 0x1c011>,
        Unimoji<"diamond", 0x1c012>, Unimoji<"diamonds", 0x1c013>,
        // Locks
        Unimoji<"locked", 0x1c01a>,  Unimoji<"lockedgray", 0x1c01b>,
        Unimoji<"unlocked", 0x1c01c>,
        // Coins
        Unimoji<"goldcoin", 0x1c020>,           Unimoji<"uncollectedusercoin", 0x1c021>,
        Unimoji<"usercoinunverified", 0x1c022>, Unimoji<"usercoin", 0x1c023>,
        Unimoji<"points", 0x1c024>,
        // Mod badges
        Unimoji<"mod", 0x1c02a>, Unimoji<"eldermod", 0x1c02b>,
        Unimoji<"leaderboardmod", 0x1c02c>,
        // Misc
        UnimojiUtf8<"star", "⭐", U"⭐">,  UnimojiUtf8<"moon", "🌙", U"🌙">,
        UnimojiUtf8<"check", "✔️", U"✔️">, UnimojiUtf8<"cross", "❌", U"❌">,
        UnimojiUtf8<"like", "👍", U"👍">,  UnimojiUtf8<"dislike", "👎", U"👎">
    >,
    EmojiGroup<
        "Twemoji", ":sunglasses:",
        // People
        UnimojiUtf8<"face_holding_back_tears", "🥹", U"🥹">,    UnimojiUtf8<"slight_smile", "🙂", U"🙂">,
        UnimojiUtf8<"wink", "😉", U"😉">,                       UnimojiUtf8<"heart_eyes", "😍", U"😍">,
        UnimojiUtf8<"smiling_face_with_3_hearts", "🥰", U"🥰">, UnimojiUtf8<"face_with_raised_eyebrow", "🤨", U"🤨">,
        UnimojiUtf8<"face_with_monocle", "🧐", U"🧐">,          UnimojiUtf8<"nerd", "🤓", U"🤓">,
        UnimojiUtf8<"star_struck", "🤩", U"🤩">,                UnimojiUtf8<"sunglasses", "😎", U"😎">,
        UnimojiUtf8<"pensive", "😔", U"😔">,                    UnimojiUtf8<"worried", "😟", U"😟">,
        UnimojiUtf8<"pleading_face", "🥺", U"🥺">,              UnimojiUtf8<"cry", "😢", U"😢">,
        UnimojiUtf8<"sob", "😭", U"😭">,                        UnimojiUtf8<"exploding_head", "🤯", U"🤯">,
        UnimojiUtf8<"scream", "😱", U"😱">,                     UnimojiUtf8<"fearful", "😨", U"😨">,
        UnimojiUtf8<"thinking", "🤔", U"🤔">,                   UnimojiUtf8<"shushing_face", "🤫", U"🤫">,
        UnimojiUtf8<"face_vomiting", "🤮", U"🤮">,              UnimojiUtf8<"smiling_imp", "😈", U"😈">,
        UnimojiUtf8<"clown", "🤡", U"🤡">,                      UnimojiUtf8<"ghost", "👻", U"👻">,
        UnimojiUtf8<"skull", "💀", U"💀">,                      UnimojiUtf8<"alien", "👽", U"👽">,
        UnimojiUtf8<"robot", "🤖", U"🤖">,                      UnimojiUtf8<"clap", "👏", U"👏">,
        UnimojiUtf8<"middle_finger", "🖕", U"🖕">,              UnimojiUtf8<"pray", "🙏", U"🙏">,
        UnimojiUtf8<"tongue", "👅", U"👅">,                     UnimojiUtf8<"speaking_head", "🗣️", U"🗣️">,
        UnimojiUtf8<"baby", "👶", U"👶">,                       UnimojiUtf8<"deaf_person", "🧏", U"🧏">,
        UnimojiUtf8<"deaf_woman", "🧏‍♀️", U"🧏‍♀️">,                 UnimojiUtf8<"deaf_man", "🧏‍♂️", U"🧏‍♂️">,
        UnimojiUtf8<"person_in_steamy_room", "🧖", U"🧖">,      UnimojiUtf8<"crown", "👑", U"👑">,
        // Nature
        UnimojiUtf8<"dog", "🐶", U"🐶">,                 UnimojiUtf8<"cat", "🐱", U"🐱">,
        UnimojiUtf8<"fox", "🦊", U"🦊">,                 UnimojiUtf8<"bear", "🐻", U"🐻">,
        UnimojiUtf8<"pig", "🐷", U"🐷">,                 UnimojiUtf8<"monkey_face", "🐵", U"🐵">,
        UnimojiUtf8<"see_no_evil", "🙈", U"🙈">,         UnimojiUtf8<"hear_no_evil", "🙉", U"🙉">,
        UnimojiUtf8<"speak_no_evil", "🙊", U"🙊">,       UnimojiUtf8<"fish", "🐟", U"🐟">,
        UnimojiUtf8<"wilted_rose", "🥀", U"🥀">,         UnimojiUtf8<"sun_with_face", "🌞", U"🌞">,
        UnimojiUtf8<"full_moon_with_face", "🌝", U"🌝">, UnimojiUtf8<"new_moon_with_face", "🌚", U"🌚">,
        UnimojiUtf8<"last_quarter_moon", "🌗", U"🌗">,   UnimojiUtf8<"new_moon", "🌑", U"🌑">,
        UnimojiUtf8<"sparkles", "✨", U"✨">,            UnimojiUtf8<"fire", "🔥", U"🔥">,
        UnimojiUtf8<"snowflake", "❄️", U"❄️">,
        // Food
        UnimojiUtf8<"eggplant", "🍆", U"🍆">,
        // Activities
        UnimojiUtf8<"trophy", "🏆", U"🏆">,       UnimojiUtf8<"first_place", "🥇", U"🥇">,
        UnimojiUtf8<"second_place", "🥈", U"🥈">, UnimojiUtf8<"third_place", "🥉", U"🥉">,
        UnimojiUtf8<"medal", "🏅", U"🏅">,
        // Travel
        UnimojiUtf8<"rocket", "🚀", U"🚀">, UnimojiUtf8<"flying_saucer", "🛸", U"🛸">,
        UnimojiUtf8<"moyai", "🗿", U"🗿">,
        // Objects
        UnimojiUtf8<"camera_with_flash", "📸", U"📸">,
        UnimojiUtf8<"gun", "🔫", U"🔫">,
        UnimojiUtf8<"sleeping_accommodation", "🛌", U"🛌">,
        UnimojiUtf8<"party_popper", "🎉", U"🎉">,
        // Symbols
        UnimojiUtf8<"heart", "❤️", U"❤️">,       UnimojiUtf8<"broken_heart", "💔", U"💔">,
        UnimojiUtf8<"radioactive", "☢️", U"☢️">, UnimojiUtf8<"100", "💯", U"💯">,
        UnimojiUtf8<"question", "❓", U"❓">,    UnimojiUtf8<"bangbang", "‼️", U"‼️">,
        UnimojiUtf8<"zero", "0️⃣", U"0️⃣">,        UnimojiUtf8<"one", "1️⃣", U"1️⃣">,
        UnimojiUtf8<"two", "2️⃣", U"2️⃣">,         UnimojiUtf8<"three", "3️⃣", U"3️⃣">,
        UnimojiUtf8<"four", "4️⃣", U"4️⃣">,        UnimojiUtf8<"five", "5️⃣", U"5️⃣">,
        UnimojiUtf8<"six", "6️⃣", U"6️⃣">,         UnimojiUtf8<"seven", "7️⃣", U"7️⃣">,
        UnimojiUtf8<"eight", "8️⃣", U"8️⃣">,       UnimojiUtf8<"nine", "9️⃣", U"9️⃣">,
        // Alternative names
        UnimojiUtf8<"shocked_face", "😱", U"😱", true>,
        UnimojiUtf8<"folded_hands", "🙏", U"🙏", true>,
        UnimojiUtf8<"tada", "🎉", U"🎉", true>
    >,
    EmojiGroup<
        "Legacy Set", ":ned:",
        Unimoji<"amongus", 0x1c030>,         Unimoji<"amogus", 0x1c031>,
        Unimoji<"bruh", 0x1c032>,            Unimoji<"carlos", 0x1c033>,
        Unimoji<"clueless", 0x1c034>,        Unimoji<"despair", 0x1c035>,
        Unimoji<"despair2", 0x1c036>,        Unimoji<"ned", 0x1c037>,
        Unimoji<"pusab?", 0x1c038>,          Unimoji<"robsmile", 0x1c039>,
        Unimoji<"sip", 0x1c03a>,             Unimoji<"splat", 0x1c03b>,
        Unimoji<"teehee", 0x1c03c>,          Unimoji<"trollface", 0x1c03d>,
        Unimoji<"true", 0x1c03e>,            Unimoji<"walter", 0x1c03f>,
        Unimoji<"wha", 0x1c040>,             Unimoji<"whadahell", 0x1c041>,
        Unimoji<"youshould", 0x1c042>,       Unimoji<"car", 0x1c043>,
        Unimoji<"zoink", 0x1c044>,           Unimoji<"shocked", 0x1c045>,
        Unimoji<"poppinbottles", 0x1c046>,   Unimoji<"party", 0x1c047>,
        Unimoji<"potbor", 0x1c048>,          Unimoji<"dabmeup", 0x1c049>,
        Unimoji<"fireinthehole", 0x1c04a>,   Unimoji<"finger", 0x1c04b>,
        Unimoji<"soggy", 0x1c04c>,           Unimoji<"mayo", 0x1c04d>,
        Unimoji<"divine", 0x1c04e>,          Unimoji<"bueno", 0x1c04f>,
        Unimoji<"rattledash", 0x1c050>,      Unimoji<"gd", 0x1c051>,
        Unimoji<"geode", 0x1c052>,           Unimoji<"boar", 0x1c053>,
        Unimoji<"mewhen", 0x1c054>,          Unimoji<"changetopic", 0x1c055>,
        Unimoji<"touchgrass", 0x1c056>,      Unimoji<"gggggggg", 0x1c057>,
        Unimoji<"gdok", 0x1c058>,            Unimoji<"hug", 0x1c059>,
        Unimoji<"angy", 0x1c05a>,            Unimoji<"lewd", 0x1c05b>,
        Unimoji<"headpat", 0x1c05c>,         Unimoji<"transcat", 0x1c05d>,
        Unimoji<"transcat2", 0x1c05e>,       Unimoji<"skillissue", 0x1c05f>,
        Unimoji<"yes", 0x1c060>,             Unimoji<"gunleft", 0x1c061>,
        Unimoji<"gunright", 0x1c062>,        Unimoji<"edge", 0x1c063>,
        Unimoji<"cologne", 0x1c064>,         Unimoji<"globed", 0x1c065>,
        Unimoji<"levelthumbnails", 0x1c066>, Unimoji<"oh", 0x1c067>,
        Unimoji<"holymoly", 0x1c068>,        Unimoji<"1000yardstare", 0x1c069>,
        Unimoji<"spunchbob", 0x1c06a>,       Unimoji<"freakbob", 0x1c06b>,
        Unimoji<"nuhuh", 0x1c06c>,           Unimoji<"yuhuh", 0x1c06d>,
        // Animated
        Unimoji<"shiggy", 0x1c600, true>,     Unimoji<"hype", 0x1c601, true>,
        Unimoji<"petmaurice", 0x1c602, true>, Unimoji<"bonk", 0x1c603, true>,
        Unimoji<"partying", 0x1c604, true>,   Unimoji<"ned_explosion", 0x1c605, true>,
        Unimoji<"polarbear", 0x1c606, true>,  Unimoji<"colonthreecat", 0x1c607, true>,
        Unimoji<"deltaruneexplosion", 0x1c60b, true>
    >,
    EmojiGroup<
        "Custom Emojis", ":eyesShock:",
        Unimoji<"eyesShock", 0x1c100>,       Unimoji<"trollskull", 0x1c101>,
        Unimoji<"laughAtThisUser", 0x1c102>, Unimoji<"ballCat", 0x1c103>,
        Unimoji<"bigBrain", 0x1c104>,        Unimoji<"breeble", 0x1c105>,
        Unimoji<"car2", 0x1c106>,            Unimoji<"frowning4", 0x1c107>,
        Unimoji<"joeDefeated", 0x1c108>,     Unimoji<"joeShrug", 0x1c109>,
        Unimoji<"letsgo", 0x1c10a>,          Unimoji<"linus", 0x1c10b>,
        Unimoji<"moyai_cube", 0x1c10c>,      Unimoji<"queminem", 0x1c10d>,
        Unimoji<"sad_markus", 0x1c10e>,      Unimoji<"spike", 0x1c10f>,
        Unimoji<"steam_happy", 0x1c110>,     Unimoji<"trol", 0x1c111>,
        Unimoji<"trolley", 0x1c112>,         Unimoji<"alphablep", 0x1c113>,
        // Animated
        Unimoji<"trolleyzoom", 0x1c60c, true>, Unimoji<"fishspin", 0x1c60d, true>,
        Unimoji<"muga", 0x1c60e, true>
        
    >,
    EmojiGroup<
        "Samsung Emojis", ":grinning:",
        Unimoji<"grinning", 0x1c300>,      Unimoji<"smiley", 0x1c301>,
        Unimoji<"yaay", 0x1c302>,          Unimoji<"cheeky", 0x1c303>,
        Unimoji<"slight_smile2", 0x1c304>, Unimoji<"blushing", 0x1c305>,
        Unimoji<"bleh", 0x1c306>,          Unimoji<"hugging", 0x1c307>,
        Unimoji<"brother", 0x1c308>,       Unimoji<"unamused", 0x1c309>,
        Unimoji<"proud", 0x1c30a>,         Unimoji<"pensive2", 0x1c30b>,
        Unimoji<"nauseated", 0x1c30c>,     Unimoji<"cool", 0x1c30d>,
        Unimoji<"whatthe", 0x1c30e>,       Unimoji<"slight_frown2", 0x1c30f>,
        Unimoji<"whatthef", 0x1c310>,      Unimoji<"cry2", 0x1c311>,
        Unimoji<"sobbing", 0x1c312>,       Unimoji<"evil", 0x1c313>,
        Unimoji<"skull2", 0x1c314>
    >,
    EmojiGroup<
        "Cube Emotes (By @cyanflower)", ":cubehappy:",
        Unimoji<"cubeballin", 0x1c071>,   Unimoji<"cubeconfused", 0x1c072>,
        Unimoji<"cubecool", 0x1c073>,     Unimoji<"cubehappy", 0x1c074>,
        Unimoji<"cubeletsgo", 0x1c075>,   Unimoji<"cubepog", 0x1c076>,
        Unimoji<"cubescared", 0x1c077>,   Unimoji<"cubestare", 0x1c078>,
        Unimoji<"cubethink", 0x1c079>,    Unimoji<"cubeview", 0x1c07a>,
        Unimoji<"cubewave", 0x1c07b>,     Unimoji<"cubewink", 0x1c07c>,
        Unimoji<"defaultangry", 0x1c07d>, Unimoji<"eeyikes", 0x1c07e>,
        Unimoji<"fumocube", 0x1c07f>,     Unimoji<"robtoppixel", 0x1c080>,
        Unimoji<"boshytime", 0x1c070>,    Unimoji<"smugzero", 0x1c081>,
        // Animated
        Unimoji<"cubedance", 0x1c608, true>, Unimoji<"cubespeen", 0x1c609, true>,
        Unimoji<"cubehyperthink", 0x1c60a, true>
    >,
    EmojiGroup<
        "Cat Emotes (C# Discord Server)", ":catgun:",
        Unimoji<"catbless", 0x1c090>,      Unimoji<"catcash", 0x1c091>,
        Unimoji<"catcomf", 0x1c092>,       Unimoji<"catcool", 0x1c093>,
        Unimoji<"catcop", 0x1c094>,        Unimoji<"catcorn", 0x1c095>,
        Unimoji<"catderp", 0x1c096>,       Unimoji<"catfacepalm", 0x1c097>,
        Unimoji<"catfine", 0x1c098>,       Unimoji<"catgasm", 0x1c099>,
        Unimoji<"catgasp", 0x1c09a>,       Unimoji<"catgift", 0x1c09b>,
        Unimoji<"catgrump", 0x1c09c>,      Unimoji<"catgun", 0x1c09d>,
        Unimoji<"cathammer", 0x1c09e>,     Unimoji<"cathi", 0x1c09f>,
        Unimoji<"cathype", 0x1c0a0>,       Unimoji<"catlaugh", 0x1c0a1>,
        Unimoji<"catlick", 0x1c0a2>,       Unimoji<"catloser", 0x1c0a3>,
        Unimoji<"catlost", 0x1c0a4>,       Unimoji<"catlove", 0x1c0a5>,
        Unimoji<"catlul", 0x1c0a6>,        Unimoji<"catlurk", 0x1c0a7>,
        Unimoji<"catmusik", 0x1c0a8>,      Unimoji<"catok", 0x1c0a9>,
        Unimoji<"catpat", 0x1c0aa>,        Unimoji<"catpls", 0x1c0ab>,
        Unimoji<"catpog", 0x1c0ac>,        Unimoji<"catpout", 0x1c0ad>,
        Unimoji<"catree", 0x1c0ae>,        Unimoji<"catshrug", 0x1c0af>,
        Unimoji<"catshy", 0x1c0b0>,        Unimoji<"catsimp", 0x1c0b1>,
        Unimoji<"catsip", 0x1c0b2>,        Unimoji<"catsleep", 0x1c0b3>,
        Unimoji<"catsmart", 0x1c0b4>,      Unimoji<"catsweat", 0x1c0b5>,
        Unimoji<"catthinking", 0x1c0b6>
    >,
    EmojiGroup<
        "Player Icons", ":default:",
        Unimoji<"default", 0x1c0c0>,       Unimoji<"sdslayer", 0x1c0c1>,
        Unimoji<"evw", 0x1c0c2>,           Unimoji<"tride", 0x1c0c3>,
        Unimoji<"colon", 0x1c0c4>,         Unimoji<"robtop", 0x1c0c5>,
        Unimoji<"wulzy", 0x1c0c6>,         Unimoji<"juniper", 0x1c0c7>,
        Unimoji<"riot", 0x1c0c8>,          Unimoji<"cyclic", 0x1c0c9>,
        Unimoji<"thesillydoggo", 0x1c0ca>, Unimoji<"uproxide", 0x1c0cb>
    >
>{};

constexpr auto EmojiReplacements = CombineReplacements(EmojiGroups);

inline static Label::EmojiMap EmojiSheet = []() {
    constexpr auto combined = CombineRegulars(EmojiGroups);
    return Label::EmojiMap(combined.begin(), combined.end());
}();

inline static Label::CustomNodeMap CustomNodeSheet = []() {
    constexpr auto combined = CombineAnimated(EmojiGroups);
    Label::CustomNodeMap res(combined.begin(), combined.end());

    // Add the mention emoji
    res.emplace(
        MentionCharStrView,
        [](std::u32string_view input, uint32_t& index) -> cocos2d::CCNode* {
            if (input.size() < 2) {
                geode::log::warn("Unexpected end of mention emoji input");
                return nullptr;
            }

            int len = input[1];
            if (input.size() < len + 2) {
                geode::log::warn("Mention emoji name too long: {} > {}", len, input.size() - 2);
                return nullptr;
            }

            auto name = input.substr(2, len);
            index += len + 1;

            auto utf8NameRes = geode::utils::string::utf32ToUtf8(name);
            if (!utf8NameRes) {
                geode::log::warn("Failed to convert mention emoji name to UTF-8");
                return nullptr;
            }

            auto utf8Name = std::move(utf8NameRes).unwrap();
            auto menu = cocos2d::CCMenu::create();
            auto label = Label::create(utf8Name, "chatFont.fnt");
            auto size = label->getContentSize();
            label->setColor({ 186, 209, 255 });
            menu->setContentSize(size);
            auto btn = geode::cocos::CCMenuItemExt::createSpriteExtra(
                label, [name = utf8Name.substr(1)](auto) {
                    cocos2d::CCDirector::get()->pushScene(cocos2d::CCTransitionFade::create(
                        0.5f, LevelBrowserLayer::scene(GJSearchObject::create(SearchType::Users, name))
                    ));
                }
            );
            menu->addChild(btn);
            btn->setPosition(size * 0.5f);
            menu->ignoreAnchorPointForPosition(false);
            return menu;
        }
    );

    return res;
}();
