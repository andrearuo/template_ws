# CMake generated Testfile for 
# Source directory: /home/user/template_ws/src/my_interfaces
# Build directory: /home/user/template_ws/build/my_interfaces
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(lint_cmake "/usr/bin/python3.10" "-u" "/home/user/ros2_humble/install/ament_cmake_test/share/ament_cmake_test/cmake/run_test.py" "/home/user/template_ws/build/my_interfaces/test_results/my_interfaces/lint_cmake.xunit.xml" "--package-name" "my_interfaces" "--output-file" "/home/user/template_ws/build/my_interfaces/ament_lint_cmake/lint_cmake.txt" "--command" "/home/user/ros2_humble/install/ament_lint_cmake/bin/ament_lint_cmake" "--xunit-file" "/home/user/template_ws/build/my_interfaces/test_results/my_interfaces/lint_cmake.xunit.xml")
set_tests_properties(lint_cmake PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/user/template_ws/src/my_interfaces" _BACKTRACE_TRIPLES "/home/user/ros2_humble/install/ament_cmake_test/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/user/ros2_humble/install/ament_cmake_lint_cmake/share/ament_cmake_lint_cmake/cmake/ament_lint_cmake.cmake;47;ament_add_test;/home/user/ros2_humble/install/ament_cmake_lint_cmake/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;21;ament_lint_cmake;/home/user/ros2_humble/install/ament_cmake_lint_cmake/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;0;;/home/user/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/user/ros2_humble/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/home/user/ros2_humble/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/home/user/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/user/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/user/template_ws/src/my_interfaces/CMakeLists.txt;40;ament_package;/home/user/template_ws/src/my_interfaces/CMakeLists.txt;0;")
add_test(xmllint "/usr/bin/python3.10" "-u" "/home/user/ros2_humble/install/ament_cmake_test/share/ament_cmake_test/cmake/run_test.py" "/home/user/template_ws/build/my_interfaces/test_results/my_interfaces/xmllint.xunit.xml" "--package-name" "my_interfaces" "--output-file" "/home/user/template_ws/build/my_interfaces/ament_xmllint/xmllint.txt" "--command" "/home/user/ros2_humble/install/ament_xmllint/bin/ament_xmllint" "--xunit-file" "/home/user/template_ws/build/my_interfaces/test_results/my_interfaces/xmllint.xunit.xml")
set_tests_properties(xmllint PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/user/template_ws/src/my_interfaces" _BACKTRACE_TRIPLES "/home/user/ros2_humble/install/ament_cmake_test/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/user/ros2_humble/install/ament_cmake_xmllint/share/ament_cmake_xmllint/cmake/ament_xmllint.cmake;50;ament_add_test;/home/user/ros2_humble/install/ament_cmake_xmllint/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;18;ament_xmllint;/home/user/ros2_humble/install/ament_cmake_xmllint/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;0;;/home/user/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/user/ros2_humble/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/home/user/ros2_humble/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/home/user/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/user/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/user/template_ws/src/my_interfaces/CMakeLists.txt;40;ament_package;/home/user/template_ws/src/my_interfaces/CMakeLists.txt;0;")
subdirs("my_interfaces__py")
