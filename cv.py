import cv2
from ultralytics import YOLO
import numpy
from serial import Serial
# Load the YOLOv8 model
model = YOLO('best.pt')
state = -1
# Open the video file
cap = cv2.VideoCapture(0)
ser = Serial('/dev/cu.usbserial-0001', 9600, timeout=0.5) # TODO: Set USB serial port 
# Loop through the video frames
while cap.isOpened():
    # Read a frame from the video
    success, frame = cap.read()

    if success:
        # Run YOLOv8 inference on the frame
        results = model(frame)
        if(len(results[0].boxes)!=0):
         #   if(float(results[0].boxes[0].conf)>0.8):
                print('Printing : \n',str(int(results[0].boxes[0].cls)),"end")
                if int(results[0].boxes[0].cls)==0:
                    ser.write('0')
                elif int(results[0].boxes[0].cls)==1:
                    ser.write('1')
                else:
                    ser.write('2')
        # Visualize the results on the frame
        # {0: 'green light', 1: 'red light', 2: 'stop sign'}

        annotated_frame = results[0].plot()

        # Display the annotated frame
        cv2.imshow("YOLOv8 Inference", annotated_frame)

        # Break the loop if 'q' is pressed
        if cv2.waitKey(1) & 0xFF == ord("q"):
            break
    else:
        # Break the loop if the end of the video is reached
        break

# Release the video capture object and close the display window
cap.release()
cv2.destroyAllWindows()