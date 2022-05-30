#include <iostream>
#include <ranges>

using namespace std;

int main()
{
    for (auto prime : (std::ranges::iota_view(1, 1000) | std::ranges::views::filter([](const auto& m) {
                           return m < 10;
                       }) |
                       std::ranges::views::take(100)))
        cout << prime << " ";
    // for (const auto prime :
    //      std::ranges::views::filter(std::ranges::views::take(std::ranges::iota_view(1), 100), [](const auto& m) {
    //          return m < 10;
    //      }))
    //     cout << prime << " ";

    //     for (const auto prime :
    //          (std::ranges::iota_view(1) | std::ranges::views::take(100)) | std::ranges::views::filter([](const auto&
    //          m) {
    //              return m < 10;
    //          }))
    //         cout << prime << " ";
}