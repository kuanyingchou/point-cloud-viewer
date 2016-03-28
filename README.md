Develop a simple viewer for 3D colorized pointclouds. 


Provide controls to 
rotate, 
zoom, 
and otherwise manipulate the view using the mouse or keyboard. 

Add on-screen controls to 

load different files, to 

control viewing options, etc...


You may choose to use OpenCV and the Point Cloud Library (PCL). The simplest pointcloud file

format to use may be .pcd, but .png formats with separate RGB and 16-bit depth data may also be a good choice. You can find a large variety of data sets here: 

http://www0.cs.ucl.ac.uk/staff/M.Firman/RGBDdatasets/

If time allows, please add some extra viewing features for pointclouds such as:

- A simple colorized meshing of the point data.

- Automatic tools for rotating the scene or flying though the cloud.

- Ability to save videos of a fly-through.

- Different color display modes – such as color by height, etc...



Please complete the following task. Use whatever tools you find appropriate (using the Internet,

for example, is assumed) but we expect original work. Linux, C++, Python, CMake, Qt, and OpenCV are preferred for development but you may use other tools if you are not familiar with these. 

Please include the following support material

- A discussion of your approach and all the assumptions and tradeoffs that you made 

- Any build configuration files and instructions for compiling

- A list of any packages/utilities required to build and execute your solution

- Any test code, or test data sets you generated

- References to other materials as appropriate

 

 Please do not spend more than 8‐10 hours on this task and feel free to ask questions. While we would love to see a completed product, we expect that your final solution may not be completely “finished” in the available time. We are more interested in seeing 


 how you approach a problem, 

 how you manage the deadline, 

 how you communicate about your work, 

 and the quality of your work product.

===============

# install

Mac OS X 10.11.4

'''
brew update
brew tap homebrew/science
brew install pcl  (may took a while)
'''

http://www.pointclouds.org/documentation/tutorials/installing_homebrew.php

Unity

- fast to develop
- fast iteration
- mobile
- easy camera movement

https://www.assetstore.unity3d.com/en/#!/content/19811


http://stackoverflow.com/questions/35328483/ld-library-not-found-for-lvtkftgl

http://www.pcl-users.org/Undefined-symbols-for-architecture-x86-64-i386-at-pcl-visualization-CloudViewer-CloudViewer-td3478272.html
