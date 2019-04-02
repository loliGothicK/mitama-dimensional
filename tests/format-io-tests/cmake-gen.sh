echo > ./CMakeLists.txt
ls -1 | sed -E 's/(.*)-tests/add_subdirectory(\1-tests)/g' \
      | grep 'add_subdirectory' \
      | xargs -I@ echo @  >> ./CMakeLists.txt
