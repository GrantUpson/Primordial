#ifndef PRIMORDIAL_UTILITY_H
#define PRIMORDIAL_UTILITY_H

#include <string>
#include <unordered_map>
#include <filesystem>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ecs/entt/entity/entity.hpp"
#include "events/Event.h"
#include "events/FastDelegate.h"

using uint64 = std::uint64_t;
using uint32 = std::uint32_t;
using uint16 = std::uint16_t;
using uint8 = std::uint8_t;

using int64 = std::int64_t;
using int32 = std::int32_t;
using int16 = std::int16_t;
using int8 = std::int8_t;

using Vector2 = glm::vec2;
using Vector3 = glm::vec3;
using Vector4 = glm::vec4;

using Matrix3 = glm::mat3;
using Matrix4 = glm::mat4;

template <typename T>
using Reference = std::shared_ptr<T>;

template <typename T>
using Scope = std::unique_ptr<T>;

using Entity = entt::entity;


class Utility {
public:
    Utility() = default;
    ~Utility() = default;

    static bool LoadSettingsFile(const std::string& filename, std::unordered_map<std::string, std::string>& map);
    static bool SaveSettingsFile(const std::string& filename, std::unordered_map<std::string, std::string>& map);
};

#endif
