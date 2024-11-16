BUILD_DIR = build
EXECUTABLE_NAME = renderer
ARGS = data/test.obj

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(INC_DIR)/*.h)

build: ${SOURCES} ${HEADERS}
	@cmake --build ${BUILD_DIR}

run: build
	@${BUILD_DIR}/${EXECUTABLE_NAME} ${ARGS}