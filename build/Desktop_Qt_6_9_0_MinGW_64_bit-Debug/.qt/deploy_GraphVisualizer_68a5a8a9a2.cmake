include("D:/Newfolder/QT/GraphVisualizer/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/GraphVisualizer-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE D:/Newfolder/QT/GraphVisualizer/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/GraphVisualizer.exe
    GENERATE_QT_CONF
)
