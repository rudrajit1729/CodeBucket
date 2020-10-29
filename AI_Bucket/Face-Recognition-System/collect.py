import cv2
import numpy as np

faceCascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

videoCapture = cv2.VideoCapture(0)
scaleFactor = 1.3
skip = 0
face_data = []
dataset_path = './data/'
file_name = input("Enter the name of the person : ")

while 1:
    ret, pic = videoCapture.read()

    faces = faceCascade.detectMultiScale(pic, scaleFactor, 5)

    if len(faces)==0:
        continue
        
    faces = sorted(faces,key=lambda f:f[2]*f[3])

    for (x,y,w,h) in faces:
        cv2.rectangle(pic, (x,y), (x+w, y+h), (255,0,0), 2)

        offset = 10
        face_section = pic[y-offset:y+h+offset,x-offset:x+w+offset]
        face_section = cv2.resize(face_section,(100,100))
        

        skip += 1
        if skip%5==0:
            face_data.append(face_section)
            print(len(face_data))

    cv2.imshow("Frame",pic)
    #cv2.imshow("Face Section",face_section)


    k = cv2.waitKey(1) & 0xff
    if k == ord("q"):
        break


# Convert our face list array into a numpy array
face_data = np.asarray(face_data)
face_data = face_data.reshape((face_data.shape[0],-1))
print(face_data.shape)

# Save this data into file system
np.save(dataset_path+file_name+'.npy',face_data)
print("Data Successfully save at "+dataset_path+file_name+'.npy')

videoCapture.release()
cv2.destroyAllWindows()

