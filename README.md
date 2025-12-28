<h1 align="center">🚦 SMART TRAFFIC LIGHT CONTROL SYSTEM</h1>
<h3 align="center">Arduino-Based System with Emergency Vehicle Detection and Boom Barriers</h3>

<p align="center">
  <i>
    Motivated by traffic congestion at urban intersections and delays faced by emergency vehicles,
    this project improves traffic efficiency, safety, and emergency response using a low-cost IoT-based solution.
  </i>
</p>

---
# 📌 **OVERVIEW**
This project is an **Arduino-based Smart Traffic Light Control System** designed to improve traffic efficiency and road safety using **real-time sensors, adaptive signal timing, and automated boom barriers**.
    The system dynamically adjusts traffic signals based on **actual vehicle density** and provides **priority access for emergency vehicles** using siren detection.  
The solution was **fully designed, coded, tested, and documented**, and was **published at IEEE SusTech**, where it received **award recognition** as a high-impact smart city prototype.
    Experimental results indicate the system’s potential to **reduce intersection accidents and improve emergency vehicle clearance times** through adaptive signal control and enforcement.

----

# ⚙️ **HOW IT WORKS**

1. **Default Traffic Operation**  
   The system initially runs like a standard traffic light:
   - Red & Green: 6 seconds  
   - Yellow: 3 seconds  

2. **Traffic Density Monitoring**  
   IR and Ultrasonic sensors continuously detect vehicle presence and lane congestion.

3. **Adaptive Signal Control**  
   Signal timings dynamically adjust based on real-time traffic density.

4. **Emergency Vehicle Detection**  
   Sound sensors detect sirens and immediately trigger **signal preemption**.

5. **Wireless Controller Synchronization**  
   Dual Arduino microcontrollers communicate via the **XBee wireless protocol** for coordinated control.

6. **Boom Barrier Enforcement**  
   Servo-controlled boom barriers lower during red lights and raise during green.

7. **Manual Override (Optional)**  
   Authorized smartphone control enables manual intervention when required.

---
# 🔌 **HARDWARE & SOFTWARE COMPONENTS**

<div align="center">
<table>
<tr>
<td width="50%" valign="top">

  ### 🧱 **HARDWARE COMPONENTS**
- **Dual Arduino Microcontrollers** – Distributed control architecture  
- **IR / Ultrasonic Sensors** – Vehicle detection and density measurement  
- **Sound Sensor Module** – Emergency vehicle siren detection  
- **XBee Wireless Modules** – Inter-controller communication  
- **Servo Motors** – Automated boom barrier actuation  
- **Traffic Light LEDs** – Signal indicators  
- **Power Supply Module** – Stable and reliable power delivery  

</td>
<td width="50%" valign="top">

  ### 💻 **SOFTWARE COMPONENTS**
- **Arduino IDE** – Development, testing, and deployment  
- **C++ (Arduino)** – Embedded control logic  
- **Adaptive Timing Algorithms** – Real-time signal optimization  
- **Interrupt-Based Handling** – Emergency signal preemption  
- **Wireless Sync Logic** – XBee-based coordination  
- **Sensor Calibration Code** – Noise filtering and accuracy improvement  
</td>
</tr>
</table>
</div>

---
# 🧠 **TECHNOLOGIES USED**

<div align="center">
<table>
<tr>
<td width="33%" valign="top">

- Arduino (Dual Controller Setup)  
- C++ / Embedded Systems  
- IoT Control Logic  

</td>
<td width="33%" valign="top">

- IR Sensors  
- Ultrasonic Sensors  
- Sound Sensors  

</td>
<td width="33%" valign="top">

- XBee Wireless Protocol  
- Servo Motors  
- Real-Time Interrupts  

</td>
</tr>
</table>
</div>

---
# 🧪 **TEST SCENARIOS**
- **Normal Traffic Flow** – Stable 6s red/green, 3s yellow  
- **Emergency Vehicle Mode** – Priority green signal for emergency lanes  
- **Density-Based Control** – Extended green time for congested lanes  
- **Boom Barrier Control** – Barriers lower during red and raise during green  
- **Manual Override** – Barriers open within **1–2 seconds**
---
# 🎯 **KEY FEATURES**
- Real-time adaptive traffic signal control  
- Emergency vehicle detection and signal preemption  
- Dual microcontroller architecture with wireless synchronization  
- Automated boom barrier enforcement  
- Smartphone-based manual override  
- Low-cost and scalable smart city solution  
---
# 📊 **RESULTS & IMPACT**
- **Published as Lead Author** at the **IEEE SusTech Conference**, highlighting the system’s real-world applicability in smart city infrastructure  
- **Award-winning prototype**, recognized for innovation in intelligent traffic management and emergency response systems  
- **Presented across multiple colleges and academic institutions**, demonstrating practical IoT and embedded systems engineering  
- Experimental testing and simulations **projected a reduction in intersection accidents** by enforcing signal compliance through boom barriers  
- **Significantly reduced emergency vehicle response time** through real-time siren detection and signal preemption  
- Improved traffic flow efficiency by dynamically adapting signal timing based on real-time vehicle density  
- Validated as a **scalable, low-cost smart traffic solution** suitable for urban intersections

# 📌 **ACADEMIC PUBLICATION & POSTER**

### 📄 IEEE Research Paper (Lead Author)
**Smart Traffic Light Control with Emergency Vehicle Detection and Boom Barriers Using Arduino**  
**Role:** Lead Author  
**Conference:** IEEE SusTech  

This research presents a fully implemented IoT-based traffic control system that demonstrates
measurable improvements in traffic efficiency, emergency response prioritization,
and intersection safety through adaptive signal control and automated enforcement mechanisms.

🔗 https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=11025771&isnumber=11025534

### 🖼️ Research Poster
<img src="poster.JPG" width="800">

---

<p align="center">
  <b>Happy Learning! 🚀</b><br>
  Thanks for visiting this project and taking the time to explore my work.
</p>
