#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

struct Animal {
    Animal(std::string name, std::string sound) :
        name(name), sound(sound) {}

    std::string name;
    std::string sound;
};

typedef std::map<std::string, std::vector<Animal> > FarmMap;

std::vector<std::pair<const char*, const char*> > make_default_animals()
{
    std::vector<std::pair<const char*, const char*> > default_animals;
    default_animals.push_back(std::make_pair("cow", "moo"));
    default_animals.push_back(std::make_pair("cat", "meow"));
    default_animals.push_back(std::make_pair("dog", "woof"));
    return default_animals;
}

FarmMap make_farms(const std::vector<std::pair<const char*, const char*> >& default_animals)
{
    const std::string farmers[] = {
        "A. D. Makepeace",
        "Old MacDonald",
        "Jimmy Carter",
    };

    FarmMap farms;
    for (const std::string *it = std::begin(farmers); it != std::end(farmers); ++it) {
        const std::string& who = *it;

        std::vector<Animal> animals;
        animals.push_back(Animal("security system", "welcome home " + who));

        typedef std::vector<std::pair<const char*, const char*> >::const_iterator Iter;
        for (Iter jt = default_animals.begin(); jt != default_animals.end(); ++jt) {
            animals.push_back(Animal(jt->first, jt->second));
        }

        farms[who] = animals;
    }
    return farms;
}

void print_farm(const FarmMap& farms, const std::string& who)
{
    std::cout << who << " has a farm...\n";
    FarmMap::const_iterator it = farms.find(who);
    if (it != farms.end()) {
        for (std::vector<Animal>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt) {
            std::string noise = jt->sound;
            if (noise.size() <= 4) {
                noise += " " + noise;
            }
            std::cout << " And on that farm there is a " << jt->name << "...\n";
            std::cout << "  with a '" << noise << "' here and a '" << noise << "' there.\n";
        }
    }
}

int main()
{
    std::vector<std::pair<const char*, const char*> > default_animals = make_default_animals();
    std::map<std::string, std::vector<Animal> > farms = make_farms(default_animals);
    print_farm(farms, "Old MacDonald");
    print_farm(farms, "A. D. Makepeace");
}
