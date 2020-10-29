# Face Recognition System

- Applied K Nearest Neighbour classification algorithm in face recognition using opencv and HaarCascades CNN
Model for frontal face detection. 

- **Tech Stack** - Python, ML(KNN), OpenCV
- It is written completely in Python 3.6.

### To run this program you need the following things installed - 
1) OpenCV 3+ (pip3 installed opencv-python)
2) NumPy  (pip3 install numpy)
3) You will also need to have the harcascade frontal face classifier(included here).
4) You should have a webcam attached to your system.

### Instructions to use the program - 

Open the collect.py file and run it will collect the datas and store it in a directory named "data".
Then open the recognizer.py file to start recognizing faces.

### Other Instructions - 
If you have multiple cameras set up to your system change the id in **cv2.VideoCapture** according to it. Usually attached webcams have id 0.
