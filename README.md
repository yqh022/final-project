# Final project progression
## week1
In conducting the brainstorming process, I set out to clarify my research question in order to choose a more focused direction for exploring wearable devices. By delving into the wearables-related resource sites and papers provided by my mentor, I worked to gain a deeper understanding of the foundational examples of wearable devices and how they interact.

During this phase, I paid particular attention to gathering information about similar products and technologies in order to gain a comprehensive understanding of the current application scenarios and prospective needs of wearable devices in different fields. By analysing this information, I was able to get a clearer grasp of market trends and user needs, and thus find a more innovative and practical direction in my research.

This stage of work has given me a deeper understanding of the field of wearable devices, providing a solid foundation for subsequent research and design work, and making useful contributions to future projects.

## week2
My focus is on addressing the often overlooked issues related to injuries arising from casual sports activities. Through extensive literature research, I have chosen to specifically concentrate on Achilles tendon injuries, a common tendon injury in leisure sports. Achilles tendon injuries are not only prevalent but also have a prolonged recovery time, potentially impacting subsequent activities.

With a clear research direction, I am targeting users who engage in casual sports rather than professional athletes. In the initial design considerations, I plan to develop a wearable device that meticulously monitors data associated with the Achilles tendon during physical activities. Through this device, I aim to provide timely information about the condition of the Achilles tendon and issue alerts to users in case of potential injury signs, reducing potential risks. Such a design is intended to offer comprehensive health care for casual sports enthusiasts, enhancing their sense of safety and comfort during physical activities.

## week3
Before initiating the design process, I conducted a thorough literature review and examined examples of existing wearable devices to confirm the sensors needed for my project. Focusing on three key factors influencing Achilles tendon health, I gathered the following information:

Achilles Tendon Function and Ankle Pronation:
The primary function of the Achilles tendon is to serve as a mechanical buffer, with its hardness increasing as the ankle pronation angle rises. When the hardness is high, the risk of Achilles tendon injury or tear increases with the greater angle of ankle pronation (1). During physical activities, the Achilles tendon undergoes uneven mechanical loads due to sudden accelerations and decelerations, making it more susceptible to tears.

Knee Joint Bend Angle:
The bending angle of the knee joint plays a crucial role in movement, particularly during activities such as running, jumping, and rapid changes of direction. The angle of knee joint flexion can impact the tension and load on the Achilles tendon. Incorrect knee joint angles may increase pressure on the Achilles tendon, raising the risk of injury (2).

Stride Length and Gait:
Stride length and gait significantly affect the load on the Achilles tendon. An excessively large stride or improper step length may increase tension on the Achilles tendon, while a shorter stride weakens the impact force generated at the initial foot contact, especially during movements requiring rapid acceleration or deceleration (3).


In order to capture data pertinent to these three influencing factors, I have opted to employ a combination of stretch sensors, flex sensors, and distance sensors.This sensor fusion strategy aims to offer a holistic dataset, facilitating a nuanced understanding of the interplay between these factors and their collective influence on Achilles tendon health during different physical activities.

## week4
I purchased two different stretch sensors and conducted separate connection tests for each. However, considering the comfort of wear and compatibility with the heel section, I found that neither of them met the expected criteria. In a meeting with my thesis advisor, I learned about relevant courses on digital knitting offered by CCI. Following an in-depth discussion with the technical support teacher, they suggested that I try using conductive yarn knitting. This type of knitting material can decrease the resistance value when stretched. In the CCI course, Agnes demonstrated how to integrate conductive yarn knitting to create a breathing light circuit, providing valuable assistance to my design. This experience not only introduced a new technical direction for my project but also offered innovative solutions to address design challenges.

![IMG_9367](https://github.com/yqh022/final-project/assets/119873931/cf59205a-9c48-46a2-833e-ee22d579bbeb)
![IMG_9753](https://github.com/yqh022/final-project/assets/119873931/11dea43d-f738-41a8-8113-2fc499d07451)

## week5
When considering the output section, I was inspired by a design I had previously seen while browsing digital interaction designs. A design that interacts with music by stepping on the carpet in different positions. I decided to incorporate robotic arm painting as my output part, which can make a personalised motion image for the user when the sensor reads the motion state data of different people.I bought laser-cut parts, started assembling my robot arm, and tried to understand how the robot arm would move according to commands by controlling four servos.I spliced the arm and adjusted all four servos to the initialised angle.

![IMG_9755](https://github.com/yqh022/final-project/assets/119873931/65758070-fc8e-4696-b907-aae8f85e2c2b)
![IMG_9756](https://github.com/yqh022/final-project/assets/119873931/5d188343-fa03-41ec-8e5b-5448d8f3abec)
![IMG_9757](https://github.com/yqh022/final-project/assets/119873931/fdd288a1-a08f-4e76-84da-babb8b2be4db)

## week6
I scheduled a course on conductive yarn knitting and created three different stretch sensors by varying the number of strands in the yarn, specifically designed to wrap around the heel section. After conducting tests, I chose the most sensitive and stable sensor among them as the optimal choice for my project. This process allowed me to fine-tune the design and ensure that the selected stretch sensor meets the desired criteria for sensitivity and stability during stretching.

![IMG_9759](https://github.com/yqh022/final-project/assets/119873931/6874a43d-160f-467d-b469-8f678c05440b)
![IMG_9760](https://github.com/yqh022/final-project/assets/119873931/e643cfc5-17d0-42b5-9872-6b2ebb29a487)
![IMG_9761](https://github.com/yqh022/final-project/assets/119873931/d38f0791-223d-4080-9d5f-2862051abaf9)

## week7
Due to the necessity of wirelessly transmitting data from the wearable device to control an Arduino board that operates a robotic arm for drawing, I explored wireless communication options. Following Matt's recommendation, I discovered that the ESP32 is capable of transmitting data through WiFi. After thorough research, I decided to implement a system with two ESP32 modules. The first ESP32 processes data received via a serial port and transmits it over WiFi. The second ESP32 receives the signal, and its processing unit analyzes the data, generating control signals. These control signals are then transmitted through a hardware connection to an Arduino development board, guiding the movement of servos and directing the robotic arm to execute the drawing. This approach allows for efficient and wireless communication between the wearable device and the drawing mechanism.

![IMG_9762](https://github.com/yqh022/final-project/assets/119873931/4456cbb4-2e84-4f5b-b723-30765dd09bab)

However, I encountered challenges while using the ESP32. The Arduino board connected to the receiving sensor was successfully collecting and transmitting data, the first ESP32 was capable of receiving and sending the data to another ESP32. Still, the second Arduino board was unable to receive the transmitted data. In consultation with my advisor, we conducted thorough tests on both the code and hardware, finding no apparent issues. Faced with this challenge, the suggestion was made to replace the WiFi-based communication with a Bluetooth module. Considering that the servo motors of the robotic arm operate on a 5V working voltage, the alternative solution involved attempting to replace the receiving Arduino board to resolve the compatibility issue.

## week8
Eventually I managed to receive data by replacing the Arduino board with an Arduino 2560. Since the Arudino has only one Rx and Tx to receive and send serial data, there is no way to send signals to the servo at the same time as receiving them.

![IMG_9766](https://github.com/yqh022/final-project/assets/119873931/88a2a495-6720-4c37-944b-b725b8e00aad)

Next, I proceeded to connect all the sensors and monitored the data transmission through the four ports on the computer.  At this stage, my focus was on assessing how the sensor placement affected the recognition performance.

Firstly, I ensured that all sensors were correctly connected to their respective ports and monitored their data transmission through the computer.  This involved meticulous debugging and testing to ensure the sensors operated correctly and accurately transmitted information.  Throughout the connection process, I closely monitored the real-time data from each sensor to ensure they communicated as expected.

Subsequently, I conducted a series of experiments by adjusting the sensor positions to assess their impact on motion recognition.  This involved placing sensors at different angles and orientations to simulate diverse motion scenarios that might be encountered in real-world usage.  Through these tests, I gained a more comprehensive understanding of how sensors performed under various conditions, enabling further optimization of the system's design.

## week9
After the test, the sensor was fixed on the strap and tested again. I found that the bending sensor was easy to contact poorly during the test, so I fixed and welded the sensor twice.Complete the writing of the literature review part of the Dissertation.
![IMG_9769](https://github.com/yqh022/final-project/assets/119873931/a657c6b4-d847-4cb9-a240-e82c5670ae52)
![IMG_9768](https://github.com/yqh022/final-project/assets/119873931/6493e998-b82d-4f60-9dda-f63a95b7f9fa)

## week10
Testing the information transmission between the wearable device and the robotic arm drawing component revealed a limitation in the approach of only considering the maximum readings during a certain period of motion. It was observed that relying solely on the maximum values within a timeframe did not effectively monitor the continuous state of the Achilles tendon over an extended duration. This is particularly crucial as overuse is one of the contributing factors to Achilles tendon injuries.

To address this issue, further exploration and refinement of the data collection and interpretation methods were undertaken. A more dynamic and continuous assessment approach was considered to capture nuanced changes in the Achilles tendon state during prolonged movement. This refinement aimed to enhance the device's capability to detect patterns associated with overuse, providing a more comprehensive understanding of the user's physiological condition during various physical activities.

Complete the methodology part of the Dissertation

## week11
Therefore, in the subsequent iterations of the design, my research proposed a method to adjust the size of the graphs drawn by the manipulator according to different values of signal conduction . It adjusts the size of the graphs drawn by the manipulator according to different values of signal conduction, so as to observe the user's motion state more intuitively.

To achieve the requirement of controlling the manipulator to draw different sizes and patterns based on sensor data, two main issues need to be addressed. Firstly, the speed of partial data acquisition of the sensor is too fast, and at the same time the speed delay of transmission to ESP32 may cause data loss. Secondly, at the receiving end, the sensor type needs to be identified and the information is transmitted to the control board controlling the servo according to different numbers.

In the data acquisition phase, it is crucial to ensure that the speed of sensor data acquisition matches the processing capacity of the system. If the data collection speed is too fast, it may cause buffer overflow or transmission delay. Consider using appropriate data filtering, reducing sampling frequency, and other methods to ensure the timeliness and completeness of the data. When data is received by ESP32, a specific data format is used to achieve it. Once the sensor type is identified, the system can parse the data accordingly and take appropriate control strategies.

So I set the angle of the forearm servo to the mapped value. Set the angle of the base servo to 0+40. Increase the angle of the base servo gradually through a loop to achieve smooth motion. In order to obtain different mapping surfaces according to the transmission of different values, it is necessary to convert the data type, extract floating point numbers from the received string, and use the map function to perform numerical mapping in order to adapt to the range of servo motion.

## week12
Test the program, invite five users to test and interview, understand the improvement suggestions, and complete the content of the discussion part of the Dissertation.
![IMG_9752 2](https://github.com/yqh022/final-project/assets/119873931/7dbb98aa-b9e4-440b-9a3f-2046cba48463)
![IMG_9751 2](https://github.com/yqh022/final-project/assets/119873931/d6dd6440-f068-4ce6-8938-4522201f4406)

## week13
Continue to complete the remaining part of the test and Dissertation, try to solve the lag problem in the signal transmission process, understand the limitations of the program, and determine the future research direction
