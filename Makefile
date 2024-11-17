BUILD_DIR = build
DATA_DIR = data
EXECUTABLE_NAME = renderer
f ?= test

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(INC_DIR)/*.h)

build: ${SOURCES} ${HEADERS}
	@cmake --build ${BUILD_DIR}

run: build
	@${BUILD_DIR}/${EXECUTABLE_NAME} ${DATA_DIR}/${f}.obj

.PHONY: build