vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO stiffstream/sobjectizer
    REF "v.${VERSION}"
    SHA512 9484ef5fd07deb6c82dba868f089fbdfbae34b33380cd25cdb40ba57468b429e8746e76a4fd1808f33f3609f143150d17966642816b27a78e7a1153520b28f0e
)

string(COMPARE EQUAL "${VCPKG_LIBRARY_LINKAGE}" "static" SOBJECTIZER_BUILD_STATIC )
string(COMPARE EQUAL "${VCPKG_LIBRARY_LINKAGE}" "dynamic" SOBJECTIZER_BUILD_SHARED)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}/dev"
    OPTIONS
        -DSOBJECTIZER_BUILD_STATIC=${SOBJECTIZER_BUILD_STATIC}
        -DSOBJECTIZER_BUILD_SHARED=${SOBJECTIZER_BUILD_SHARED}
)

vcpkg_cmake_install()

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")

vcpkg_cmake_config_fixup(CONFIG_PATH lib/cmake/sobjectizer)

file(INSTALL "${SOURCE_PATH}/LICENSE" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}" RENAME copyright)

