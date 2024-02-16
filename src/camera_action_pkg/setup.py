from setuptools import find_packages, setup

package_name = 'camera_action_pkg'

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
            'camera_action_node = camera_action_pkg.camera_action_node:main',
            'camera_action_server_node = camera_action_pkg.camera_action_server_node:main',
            'camera_action_client_node = camera_action_pkg.camera_action_client_node:main'
        ],
    },
)
