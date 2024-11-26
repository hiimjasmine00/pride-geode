#pragma once

#include <Geode/Geode.hpp>
#include <array>
#include <string>

/// @brief Streak data.
struct PrideStreakData final {
    std::string name;
    std::array<cocos2d::ccColor3B, 3> colors; ///< For rainbow effect.
};

template<>
struct matjson::Serialize<PrideStreakData> {
    static geode::Result<PrideStreakData> fromJson(const matjson::Value& json) {
        return geode::Ok(PrideStreakData {
            .name = json["name"].asString().unwrapOr(""),
            .colors = {{
                json["colors"][0].as<cocos2d::ccColor3B>().unwrapOr(cocos2d::ccColor3B { 0, 0, 0 }),
                json["colors"][1].as<cocos2d::ccColor3B>().unwrapOr(cocos2d::ccColor3B { 0, 0, 0 }),
                json["colors"][2].as<cocos2d::ccColor3B>().unwrapOr(cocos2d::ccColor3B { 0, 0, 0 }),
            }}
        });
    }
};
