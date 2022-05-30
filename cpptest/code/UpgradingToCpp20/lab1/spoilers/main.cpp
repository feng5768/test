#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

struct Animal
{
    std::string name;
    std::string sound;
};

using FarmMap = std::map<std::string, std::vector<Animal>>;

auto make_default_animals() -> std::vector<std::pair<const char*, const char*>>
{
    return {
        {"cow", "moo"},
        {"cat", "meow"},
        {"dog", "woof"},
    };
}

auto make_farms(const auto& default_animals)
{
    std::string farmers[] = {
        "A. D. Makepeace",
        "Old MacDonald",
        "Jimmy Carter",
    };

    FarmMap farms;
    for (const std::string& who : farmers)
    {
        std::vector animals = {
            Animal{"security system", "welcome home " + who},
        };
        for (const auto& [name, sound] : default_animals)
        {
            animals.push_back({name, sound});
        }

        farms[who] = std::move(animals);
    }
    return farms;
}

void print_farm(const FarmMap& farms, const std::string& who)
{
    std::cout << who << " has a farm...\n";
    if (auto it = farms.find(who); it != farms.end())
    {
        const auto& [farmer, animals] = *it;  // In C++20, this can move into the for-loop-header
        assert(farmer == who);
        for (auto [name, noise] : animals)
        {
            if (noise.size() <= 4)
            {
                noise += " " + noise;
            }
            std::cout << " And on that farm there is a " << name << "...\n";
            std::cout << "  with a '" << noise << "' here and a '" << noise << "' there.\n";
        }
    }
}

int main()
{
    auto    default_animals = make_default_animals();
    FarmMap farms           = make_farms(default_animals);
    print_farm(farms, "Old MacDonald");
    print_farm(farms, "A. D. Makepeace");
}
