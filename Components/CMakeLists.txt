add_library(Components Src/HealthComponent.cpp Src/MoveComponent.cpp Src/LifeTimeComponent.cpp Src/WeaponComponent.cpp)

target_include_directories(Components PUBLIC Inc)