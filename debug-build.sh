# This has only been tested on Linux Mint
#!/bin/bash

CLEAR_BUILD=false
RUN_PROGRAM=false

# Checks flags
# Idk why case statements look so weird in bash but it works lol
# Use -r to run the program after building and use -c to clear the build folder after running
while getopts "cr" opt; do
  case "$opt" in
    c)
      CLEAR_BUILD=true
      ;;
    r)
      RUN_PROGRAM=true
      ;;
  esac
done

# Builds Crab Crawler
cmake -DCMAKE_BUILD_TYPE=Release -S ./ -B ./build
cmake --build ./build

# Runs the program if the -r flag is provided
if $RUN_PROGRAM; then
  echo "Running the Build..."
  ./build/CrabCrawler
fi

if $CLEAR_BUILD; then
  echo "Clearing build folder..."
  rm -rf build
fi