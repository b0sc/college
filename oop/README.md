# OOP

> Theory part covers topics like Object, Class, Data
> Abstraction, Encapsulation, Inheritance,
> Polymorphism, Dynamic Binding, and Message
> Passing.

> This course is designed to help students understand the practical implementations of those thoeritical concepts taught in syllabus.

## How to Submit?

Inside the `[taskname]` folder, there is a `README.md` file that you will write, how OOP concept is implemented. Code in any of `Python, Java, C++, JavaScript, PHP` extension file to recreate the already available example. You can follow this same format to submit your task.

-   Introduction to Example
-   Explanation of the code (How is OOP Implemented)
-   Output of the code `screenshots`.

When done, there should be two edited files in the `[taskname]` folder: `README.md` and the code file `[taskname].cpp` and any required pictures in the `assets` folder.

## Tasks

A version of the task example is already written in Python. You have to rewrite the code in any other language like `C++, JavaScript, PHP` as you prefer, once understood the concept, you can implement it in any language you like.

-   [ ] [Client-Server Systems](./client_server_system/)
-   [ ] [ODBMS](./odbms/)
-   [ ] [Real-Time System Design](./real_time_system/)
-   [ ] [Neural Networking and Parallel Programming](./neural_networking/)
-   [ ] [Office Automation Systems](./office_automation_system/)
-   [ ] [E-Commerce Systems](./e_commerce_system/)
-   [ ] [Task 7 TBD]()
-   [ ] [Task 8 TBD]()
-   [ ] [Task 9 TBD]()
-   [ ] [Task 10 TBD]()

### Task 1: Client-Server Systems

An instance of the Client class is created to establish a connection to the server. Once a connection is accepted by the server, communication can occur between the client and server.

Use of Classes:

-   Server Class: Initializes a server socket, binds it to a host and port, and listens for incoming connections. It provides a method (accept_connection) to accept client connections.
-   Client Class: Initializes a client socket and connects it to the server's host and port.

_Rewrite [main.py](./client_server_system/main.py) in [main.cpp](./client_server_system/main.cpp)_

### Task 2: ODBMS

A simple object-based persistence module, is used to simulate an OODBMS in Python. These databases store objects instead of data, such as real numbers and integers:

-   Person Class: Represents individuals with attributes like name and age.
-   Storing Objects in the Database: Instances of the Person class are created and stored in the database using the shelve module.
-   Retrieving Objects from the Database: Objects are retrieved from the database and their attributes are accessed and manipulated as needed.

_Rewrite [main.py](./odbms/main.py) in [main.cpp](./odbms/main.cpp)_

### Task 3: Real-Time System Design

Consider a scenario where real-time data from sensors is processed using OOP:

-   Sensor Class: Represents a sensor device with attributes such as name and methods like `read_data()` to simulate data reading.
-   RealTimeSystem Class: Aggregates sensor instances and provides methods to process data from multiple sensors in real-time.
-   Processing Data: The `process_data()` method of the RealTimeSystem class iterates through the sensors, reads data from each sensor using their `read_data()` method, and processes it as per system requirements.

_Rewrite [main.py](./real_time_system/main.py) in [main.cpp](./real_time_system/main.cpp)_

### Task 4: Neural Networking and Parallel Programming

Note the approach taken to model a simple neural network:

-   Neuron Class: Represents individual neurons in the neural network with attributes such as weights and methods to perform activation.
-   NeuralNetwork Class: Aggregates instances of Neuron to form a network and provides methods to predict outputs based on inputs.
-   Predicting Outputs: Takes input data, passes it through the network of neurons, and predicts the outputs based on the network's activation function.

_Rewrite [main.py](./neural_networking/main.py) in [main.cpp](./neural_networking/main.cpp)_

### Task 5: Office Automation Systems

OOP can be applied to model components of office automation systems in Python, showcasing encapsulation of functionalities within classes, abstraction of communication processes, and modular design for interoperability.

-   Email Class: Represents an email message with attributes such as sender, recipient, subject, and content, along with methods to send emails.
-   CalendarEvent Class: Represents a scheduled event with attributes such as title, date, and location, along with methods to schedule events.
-   Interacting with Office Tools: Instances of the Email and CalendarEvent classes are created to interact with email messaging and calendar scheduling functionalities, respectively.

_Rewrite [main.py](./office_automation_system/main.py) in [main.cpp](./office_automation_system/main.cpp)_

### Task 6: E-Commerce Systems

OOP is applied to model a simplified E-Commerce system with encapsulation of product and shopping cart functionalities, abstraction of user interactions, and modular design for scalability and flexibility in handling e-commerce operations:

-   Product Class: The Product class represents items available for purchase, with attributes such as name, price, and quantity.
-   ShoppingCart Class: The ShoppingCart class represents a user's shopping cart, with methods to add items, calculate the total price, and manage the cart contents.
-   Interacting with E-Commerce Functionality: Instances of the Product class are created to represent different products available for purchase. The ShoppingCart class is used to manage user interactions, such as adding products to the cart and calculating the total price of items in the cart.

_Rewrite [main.py](./e_commerce_system/main.py) in [main.cpp](./e_commerce_system/main.cpp)_

## Resources

-   [General OOP Concept](https://www.codeproject.com/Articles/22769/Introduction-to-Object-Oriented-Programming-Concep)
-   [StackOverflow](https://softwareengineering.stackexchange.com/questions/205459/object-oriented-design)
