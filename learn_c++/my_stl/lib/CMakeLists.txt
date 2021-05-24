# 현재 디렉토리에 있는 모든 파일을 SRC_FILES 변수에 추가한다.
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(mystl STATIC ${SRC_FILES})

# stl 의 include 경로 지정
target_include_directories(mystl PUBLIC ${CMAKE_SOURCE_DIR}/include)

# stl 의 컴파일 옵션 지정
target_compile_options(mystl PRIVATE -Wall -Werror)

# stl 를 C++ 17 로 컴파일
target_compile_features(mystl PRIVATE cxx_std_17)

# stl 에 링크
target_link_libraries(mystl PRIVATE)
