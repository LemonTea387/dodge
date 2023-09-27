# dodge-platformer
A simple platformer... just to test your reflex.

# Building
## Windows
Set The path variables.
```
Set-Variable -Name "SDL_PATH" -Value "[SDL_PATH]"
Set-Variable -Name "SDL_IMAGE_PATH" -Value "[SDL_image_PATH]"
```
### Generating Build files
```
cmake -DCMAKE_INSTALL_PREFIX="$SDL_PATH\cmake;$SDL_IMAGE_PATH\cmake" -B .\build
```
### Build 
```
cmake --build .\build
```
