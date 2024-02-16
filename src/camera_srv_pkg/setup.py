from setuptools import find_packages, setup

package_name = 'camera_srv_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='andrea',
    maintainer_email='241627@studenti.unimore.it',
    description='example python pkg',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            #<-- Insert here your entry_points for the executable scripts -->
            'camera_srv_node = camera_srv_pkg.camera_srv_node:main',
            'camera_srv_server_node = camera_srv_pkg.camera_srv_server_node:main',
            'camera_srv_client_node = camera_srv_pkg.camera_srv_client_node:main'

            #<-- ________________________________________________________ -->

        ],
    },
)
