!isEmpty(ML_INCLUDE_PRI_INCLUDED):error(hs-include.pri already included)
ML_INCLUDE_PRI_INCLUDED = 1

include(3rdparty/qpe/qpe/qpe-include.pri)

# отключаем генерацию debug и release (нужны для in-source сборки)
CONFIG -= debug_and_release debug_and_release_target

# пути к исходникам и результирующей сборке
isEmpty(ML_SRC_DIR):ML_SRC_DIR = $$PWD
isEmpty(ML_BUILD_DIR):ML_BUILD_DIR = $$shadowed($$PWD)

ML_BUILD_TEST_DIR = $$ML_BUILD_DIR/tests

ML_SRC_DIR = $$PWD

# INCLUDEPATH
INCLUDEPATH += $$ML_SRC_DIR/include
INCLUDEPATH += $$QPE_SRC_DIR/include
