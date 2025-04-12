#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>

using namespace std;

struct Question {
    std::string topic;
    bool isCorrect;
};

struct MCQ {
    string question;
    string topic;
    vector<string> options;
    char correct_option;
    int difficulty;
};

string getDifficultyName(int difficulty) {
    switch (difficulty) {
        case 1: return "Easy";
        case 2: return "Normal";
        case 3: return "Medium";
        case 4: return "Hard";
        default: return "Unknown";
    }
}

void displayQuestion(const MCQ& question) {
    cout << "Question (" << question.topic << " - Difficulty " << getDifficultyName(question.difficulty) << "): " << question.question << endl;
    for (const string& option : question.options) {
        cout << option << endl;
    }
}

char getUserAnswer() {
    char user_choice;
    cout << "Your answer (A/B/C/D): ";
    cin >> user_choice;
    return toupper(user_choice);
}

bool evaluateAnswer(const MCQ& question, char userAnswer) {
    return userAnswer == question.correct_option;
}

void printCertificateHeader() {
    cout << "=====================================" << endl;
    cout << "      CERTIFICATE OF ACHIEVEMENT      " << endl;
    cout << "=====================================" << endl;
}

void printCertificateFooter() {
    cout << "=====================================" << endl;
}

int main() {
    srand(time(nullptr));

    int currentDifficulty = 2; 
    int maxDifficulty = 4; 

    while (currentDifficulty <= maxDifficulty) {
        vector<MCQ> easyQuestions = {
    {"What is 2 + 2? (Math)", "Math", {"A) 3", "B) 4", "C) 5", "D) 6"}, 'B', 1},
    {"What is the capital of Italy? (General Knowledge)", "General Knowledge", {"A) Berlin", "B) London", "C) Rome", "D) Madrid"}, 'C', 1},
    {"What is the captial of India? (General Knowledge)", "General Knowledge", {"A) Mumbai", "B) Kerala", "C) New Delhi", "D) Gujarat"}, 'C', 1},
    {"What is 6!/2! ? (Math)", "Math", {"A) 1!", "B) 72!", "C) 72", "D) 36"}, 'C', 1},
    {"What is sin(45)? (Math)", "Math", {"A) 1/√2", "B) 1/2", "C) None of these", "D) √3/4"}, 'A', 1},
    {"Which gas is the abundant gas in atmoshpere? (Biology)", "Biology", {"A) Oxygen", "B) Carbon Dioxide", "C) Methane", "D) Nitrogen"}, 'D', 1},
    {"Which is the largest continet? (Geography)", "Geography", {"A) Asia", "B) Antartica", "C) North America", "D) Europe"}, 'A', 1},
    {"What is the output of following C++ code?\n\n (CPP)"
     "#include <iostream>\n"
     "using namespace std;\n"
     "int main()\n"
     "int n=5\n"
     "cout<<n++<<endl;\n",
     "CPP", {"A) 5", "B) 6", "C) 4", "D) 7"}, 'B', 1},
    {"What is the SI unit of force? (Physics)", "Physics", {"A) Pascal", "B) Metres", "C) Seconds", "D) Newton"}, 'D', 1},
    {"In which year did we get independence from British? (General Knowledge)", "General Knowledge", {"A) 1945", "B) 1967", "C) 1944", "D) 1954"}, 'A', 1},
    {"Who is the CEO of Apple? (General Knowledge)", "General Knowledge", {"A) Tim Cook", "B) Steve Jobs", "C) Bill Gates", "D) Sundar Pichai"}, 'A', 1},
    {"Latest phone launched by Samsung? (General Knowledge)", "General Knowledge", {"A) Galaxy s54", "B) Galaxy s23", "C) Samsung A32", "D) Samsung M48"}, 'B', 1},
    {"Which planet is known as the Red Planet ? (General Knowledge)", "General Knowledge", {"A) Venus", "B) Mars", "C) Jupiter", "D) Saturn"}, 'B', 1},
    {"If a rectangle has a length of 8 units and a width of 4 units, what is its area? (Math)", "Math", {"A) 16 square units", "B) 24 square units", "C) 32 square units", "D) 12 square units"}, 'A', 1},
    {"Which gas do plants absorb from the atmosphere during photosynthesis? (Biology)", "Biology", {"A) Oxygen", "B) Carbon dioxide", "C)  Nitrogen", "D) Hydrogen"}, 'B', 1},
    {"What is the primary output stream in C++?", "Programming", {"A) cout", "B) cin", "C) cerr", "D) clog"}, 'A', 1},
    {"Which data type is used to store whole numbers in C++?", "Programming", {"A) int", "B) double", "C) char", "D) bool"}, 'A', 1},
    {"What is the main function's return type in C++?", "Programming", {"A) void", "B) int", "C) double", "D) char"}, 'B', 1},
    {"What is the SI unit of length?", "Physics", {"A) Meter", "B) Kilogram", "C) Second", "D) Kelvin"}, 'A', 1},
    {"What gas do plants absorb from the atmosphere during photosynthesis?", "Biology", {"A) Carbon dioxide", "B) Oxygen", "C) Nitrogen", "D) Hydrogen"}, 'A', 1},
    {"What is the largest planet in our solar system?", "Astronomy", {"A) Earth", "B) Mars", "C) Jupiter", "D) Venus"}, 'C', 1},
    {"Which planet is known as the Red Planet?", "Astronomy", {"A) Venus", "B) Mars", "C) Jupiter", "D) Saturn"}, 'B', 1},
    {"What is the atomic number of carbon?", "Chemistry", {"A) 6", "B) 12", "C) 14", "D) 16"}, 'A', 1},
    {"In which continent is the Sahara Desert located?", "Geography", {"A) Asia", "B) Antarctica", "C) Africa", "D) North America"}, 'C', 1},
    {"Which programming language is known for its high-performance and is often used in game development?", "Programming", {"A) C++", "B) Python", "C) Java", "D) Ruby"}, 'A', 1},
    {"What is the process of a liquid changing into a gas at the surface of the liquid called?", "Chemistry", {"A) Sublimation", "B) Evaporation", "C) Condensation", "D) Freezing"}, 'B', 1},
    {"Which organelle is responsible for cellular respiration in a cell?", "Biology", {"A) Nucleus", "B) Mitochondria", "C) Chloroplast", "D) Endoplasmic reticulum"}, 'B', 1},
    {"What is the capital of France?", "Geography", {"A) Berlin", "B) London", "C) Rome", "D) Paris"}, 'D', 1},
    {"What is the chemical symbol for gold?", "Chemistry", {"A) Ag", "B) Ge", "C) Au", "D) Hg"}, 'C', 1},
    {"Which programming language is often used for web development and is known for its simplicity and readability?", "Programming", {"A) C++", "B) Python", "C) Java", "D) Ruby"}, 'B', 1},
    {"What is the process of changing a solid directly to a gas without becoming a liquid called?", "Chemistry", {"A) Sublimation", "B) Evaporation", "C) Condensation", "D) Melting"}, 'A', 1},
    {"What is the largest organ in the human body?", "Biology", {"A) Liver", "B) Heart", "C) Skin", "D) Brain"}, 'C', 1},
    {"Which element is essential for all organic compounds and life on Earth?", "Chemistry", {"A) Nitrogen", "B) Hydrogen", "C) Oxygen", "D) Carbon"}, 'D', 1},
    {"Which ocean is the largest on Earth?", "Geography", {"A) Atlantic Ocean", "B) Indian Ocean", "C) Pacific Ocean", "D) Arctic Ocean"}, 'C', 1},
    {"What is the chemical formula for water?", "Chemistry", {"A) CO2", "B) H2O", "C) O2", "D) CH4"}, 'B', 1},
    {"Which programming language is often used for game development and is known for its high performance?", "Programming", {"A) C++", "B) Python", "C) Java", "D) Ruby"}, 'A', 1},
    {"What is the main function's return type in C++?", "Programming", {"A) void", "B) int", "C) double", "D) char"}, 'B', 1},
    {"What is the atomic number of oxygen?", "Chemistry", {"A) 6", "B) 12", "C) 14", "D) 8"}, 'D', 1},
    {"What is the process of a gas changing into a liquid called?", "Chemistry", {"A) Sublimation", "B) Evaporation", "C) Condensation", "D) Freezing"}, 'C', 1}
};


    vector<MCQ> normalQuestions = {
    {"Who wrote 'Romeo and Juliet'? (Literature)", "Literature", {"A) Charles Dickens", "B) Jane Austen", "C) William Shakespeare", "D) Mark Twain"}, 'C', 2},
    {"What is the largest planet in our solar system? (General Knowledge)", "General Knowledge", {"A) Earth", "B) Mars", "C) Jupiter", "D) Venus"}, 'C', 2},
    {"What is the name of finance minister of India (Political Science)", "Political Science", {"A) Yogi Adityanath", "B) Nirmala Sitharaman", "C) Narendra Modi", "D) Amit Shah"}, 'B', 2},
    {"Which of these is an Extensible Markup Language (Programming)", "Programming", {"A) Python", "B) R", "C) JSON", "D) XML"}, 'D', 2},
    {"What is the name of the latest launched satellite by ISRO (General Knowledge)", "General Knowledge", {"A) Chandrayaan-3", "B) Aditya-L1", "C) Gaganyaan", "D) Tejas-2"}, 'B', 2},
    {"What is the full form of SQL? (Programming)", "Programming", {"A) Structured Query Language", "B) Standard Query Language", "C) Systematic Query Language", "D) Schematic Query Language"}, 'A', 2},
    {"In which year was the Indian Constitution established? (Political Science)", "Political Science", {"A) 1986", "B) 1952", "C) 1949", "D) 1945"}, 'C', 2},
    {"Who is the Prime Minister of the United Kingdom? (General Knowledge)", "General Knowledge", {"A) Boris Johnson", "B) Rishi Sunak", "C) Priti Patel", "D) Daniel Radcliffe"}, 'B', 2},
    {"What is the value of acceleration due to gravity? (Physics)", "Physics", {"A) 9.9 m/s^2", "B) 9.8 m/s^2", "C) 10 m/s^2", "D) 9 m/s^2"}, 'B', 2},
    {"What is the full form of RDMS? (Programming)", "Programming", {"A) Relational Database Management System", "B) Room Door Management System", "C) Random Data Mix System", "D) Rome Dubai Mumbai Singapore"}, 'A', 2},
    {"What literary term describes a brief and witty statement often containing paradox? (Literature)", "Literature", {"A) Simile", "B) Foreshadowing", "C) Irony", "D) Epigram"}, 'D', 2},
    {"What does the acronym API stand for in the context of software development? (Programming)", "Programming", {"A) Advanced Programming Interface", "B)  Application Programming Interface", "C) Automated Program Integration", "D) Advanced Protocol Instruction"}, 'B', 2},
    {"Which law of thermodynamics states that energy cannot be created or destroyed, only transferred or converted from one form to another? (Physics)", "Physics", {"A) First Law", "B) Second Law", "C) Third Law", "D) Zeroth Law"}, 'A', 2},
    {"What is the result of the following expression: 3² + 4² - 2³? (Maths)", "Maths", {"A) 9", "B) 11", "C) 5", "D) 16"}, 'B', 2},
    {"What is the value of the square root of 144? (Maths)", "Maths", {"A) 12", "B) 13", "C) 11", "D) 10"}, 'A', 2},
    {"In C++, what is a reference variable used for?", "Programming", {"A) To store the memory address of a variable", "B) To declare a constant value", "C) To provide an alias for an existing variable", "D) To create a new variable"}, 'C', 2},
    {"What is the SI unit of electric current?", "Physics", {"A) Joule", "B) Volt", "C) Ampere", "D) Watt"}, 'C', 2},
    {"Which organelle is known as the 'powerhouse' of the cell?", "Biology", {"A) Nucleus", "B) Golgi apparatus", "C) Mitochondria", "D) Endoplasmic reticulum"}, 'C', 2},
    {"What is the longest river in the world?", "Geography", {"A) Amazon River", "B) Nile River", "C) Mississippi River", "D) Yangtze River"}, 'B', 2},
    {"What is the chemical formula for methane?", "Chemistry", {"A) CH4", "B) CO2", "C) H2O", "D) O2"}, 'A', 2},
    {"Which programming language is known for its memory management capabilities through garbage collection?", "Programming", {"A) Python", "B) C++", "C) Java", "D) Ruby"}, 'C', 2},
    {"What is the speed of light in a vacuum?", "Physics", {"A) 299,792,458 meters per second", "B) 100,000,000 meters per second", "C) 186,282 miles per hour", "D) 3.14 x 10^8 meters per second"}, 'A', 2},
    {"Which gas is responsible for the Earth's ozone layer depletion?", "Environmental Science", {"A) Oxygen", "B) Carbon dioxide", "C) Chlorofluorocarbons (CFCs)", "D) Nitrogen"}, 'C', 2},
    {"What is the process by which plants make their own food using sunlight?", "Biology", {"A) Respiration", "B) Photosynthesis", "C) Fermentation", "D) Transpiration"}, 'B', 2},
    {"Which country is located in both Europe and Asia?", "Geography", {"A) Spain", "B) Turkey", "C) Egypt", "D) Brazil"}, 'B', 2},
    {"What is the chemical symbol for iron?", "Chemistry", {"A) Fe", "B) Ir", "C) Io", "D) In"}, 'A', 2},
    {"In programming, what is a 'compiler' used for?", "Programming", {"A) To execute the program", "B) To translate high-level code into machine code", "C) To manage memory allocation for the program", "D) To debug the code"}, 'B', 2},
    {"Which gas is the most abundant in Earth's atmosphere?", "Environmental Science", {"A) Oxygen", "B) Carbon dioxide", "C) Methane", "D) Nitrogen"}, 'D', 2},
    {"What is the study of the Earth's physical features and the atmosphere called?", "Geography", {"A) Geology", "B) Meteorology", "C) Geography", "D) Astronomy"}, 'C', 2},
    {"Which programming language is known for its simplicity, ease of learning, and is often used for web development?", "Programming", {"A) C++", "B) Python", "C) Java", "D) Ruby"}, 'B', 2},
    {"What is the process of a liquid changing into a gas called?", "Chemistry", {"A) Sublimation", "B) Evaporation", "C) Condensation", "D) Freezing"}, 'B', 2},
    {"Which gas is essential for respiration and is released during photosynthesis?", "Biology", {"A) Oxygen", "B) Carbon dioxide", "C) Nitrogen", "D) Hydrogen"}, 'A', 2},
    {"What is the highest mountain in the world?", "Geography", {"A) Mount Kilimanjaro", "B) Mount McKinley", "C) Mount Everest", "D) Mount Fuji"}, 'C', 2},
    {"What is the atomic number of hydrogen?", "Chemistry", {"A) 1", "B) 8", "C) 12", "D) 16"}, 'A', 2},
    {"Which programming language is known for its high-performance and is often used for game development?", "Programming", {"A) C++", "B) Python", "C) Java", "D) Ruby"}, 'A', 2}
};  

vector<MCQ> mediumQuestions = {
    {"What is the integral of x^2 with respect to x? (Math)", "Math", {"A) x + C", "B) (1/3)x^3 + C", "C) (1/2)x^2 + C", "D) 2x + C"}, 'B', 3},
    {"What is the derivative of sin(x) with respect to x? (Math)", "Math", {"A) cos(x)", "B) -cos(x)", "C) sin(x)", "D) -sin(x)"}, 'A', 3},
    {"Which part of the human brain is responsible for regulating basic life functions like breathing and heart rate? (Biology)", "Biology", {"A) Cerebrum", "B) Cerebellum", "C) Medulla oblongata", "D) Thalamus"}, 'C', 3},
    {"In Java, which keyword is used to create a new instance of a class? (Programming)", "Programming", {"A) new", "B) create", "C) instance", "D) class"}, 'A', 3},
    {"Which of these methods is a method of scaling? (Programming)", "Programming", {"A) Vectorization", "B) Normalization", "C) Transformation", "D) None of these"}, 'B', 3},
    {"What is the full form of ALU? (Programming)", "Programming", {"A) Arithmetic Logical Unit", "B) Algorithm Logical Unit", "C) Algebraic Logical Unit", "D) Arsh Logix Unit"}, 'A', 3},
    {"Is 8085 is a? (Programming)", "Programming", {"A) 16-bit processor", "B) 4-bit processor", "C) 8-bit processor", "D) Micro Padhni Baaki Hai"}, 'B', 3},
    {"Which is the full form of TCL? (Data Science)", "Data Science", {"A) Transaction Control Language", "B) Transformational Control Language", "C) Traverse Control Language", "D) Tridal Control Language"}, 'A', 3},
    {"Where did the Mahabharata war take place? (Mythology)", "Mythology", {"A) Kurukshetra", "B) Dwarka", "C) Mathura", "D) Ayodhya"}, 'A', 3},
    {"What is the full form of DDL? (Data Science)", "Data Science", {"A) Data Definition Language", "B) Data Description Language", "C) Data Design Language", "D) Data Description Language"}, 'A', 3},
    {"Who was the first Mughal Emperor of India? (History)", "History", {"A) Humayun", "B) Aurangzeb", "C) Babur", "D) Shah Jahan"}, 'C', 3},
    {"Who was the first President of the United States? (History)", "History", {"A)  Benjamin Franklin", "B)  Thomas Jefferson", "C) John Adams", "D) George Washington"}, 'D', 3},
    {"What is the primary goal of data normalization in databases? (Data Science)", "Data Science", {"A) To reduce data redundancy", "B) To increase data complexity", "C) To simplify data analysis", "D) To improve data security"}, 'A', 3},
    {"What is the SI unit of force? (Physics)", "Physics", {"A) Watt", "B) Joule", "C) Newton", "D) Tesla"}, 'C', 3},
    {"Which fundamental force is responsible for holding the nucleus of an atom together? (Physics)", "Physics", {"A) Gravitational force", "B) Electromagnetic force", "C) Strong nuclear force", "D) Weak nuclear force"}, 'C', 3},
    {"What is a 'pointer' in C++ used for?", "Programming", {"A) To store the memory address of a variable", "B) To declare a constant value", "C) To provide an alias for an existing variable", "D) To create a new variable"}, 'A', 3},
    {"What is the formula for calculating the velocity of an object?", "Physics", {"A) v = d/t", "B) v = a*t", "C) v = d*a", "D) v = a/d"}, 'A', 3},
    {"What is the primary function of the human heart?", "Biology", {"A) Pumping blood", "B) Digesting food", "C) Filtering toxins", "D) Storing oxygen"}, 'A', 3},
    {"What is the equator?", "Geography", {"A) A line of longitude", "B) A line of latitude", "C) A circle around the North Pole", "D) A circle around the South Pole"}, 'B', 3},
    {"What is the chemical symbol for gold?", "Chemistry", {"A) Go", "B) Gd", "C) Au", "D) Ag"}, 'C', 3},
    {"In C++, what is the 'const' keyword used for?", "Programming", {"A) To make a variable changeable", "B) To declare a constant value", "C) To provide an alias for an existing variable", "D) To create a new variable"}, 'B', 3},
    {"What is the force of gravity on an object with a mass of 5 kg?", "Physics", {"A) 50 N", "B) 25 N", "C) 10 N", "D) 5 N"}, 'A', 3},
    {"What is the function of the ribosomes in a cell?", "Biology", {"A) Energy production", "B) Protein synthesis", "C) DNA replication", "D) Waste elimination"}, 'B', 3},
    {"Which ocean is the largest in terms of surface area?", "Geography", {"A) Atlantic Ocean", "B) Indian Ocean", "C) Arctic Ocean", "D) Pacific Ocean"}, 'D', 3},
    {"What is the chemical formula for water?", "Chemistry", {"A) CO2", "B) H2O", "C) O2", "D) NaCl"}, 'B', 3},
    {"In C++, what is a 'class' used for?", "Programming", {"A) To declare a constant value", "B) To create a new variable", "C) To define an object's structure and behavior", "D) To provide an alias for an existing variable"}, 'C', 3},
    {"What is the acceleration due to gravity on the surface of Mars?", "Physics", {"A) 9.8 m/s^2", "B) 3.7 m/s^2", "C) 6.0 m/s^2", "D) 0.38 m/s^2"}, 'B', 3},
    {"Which part of a plant is responsible for photosynthesis?", "Biology", {"A) Roots", "B) Leaves", "C) Stems", "D) Flowers"}, 'B', 3},
    {"Which continent is often referred to as the 'Dark Continent'?", "Geography", {"A) Africa", "B) Asia", "C) Antarctica", "D) Europe"}, 'A', 3},
    {"What is the chemical symbol for carbon?", "Chemistry", {"A) Cr", "B) Co", "C) C", "D) Ca"}, 'C', 3},
    {"In C++, what is 'inheritance' used for in object-oriented programming?", "Programming", {"A) To create a new variable", "B) To provide an alias for an existing variable", "C) To define an object's structure and behavior based on another class", "D) To declare a constant value"}, 'C', 3},
    {"What is the unit of electrical resistance?", "Physics", {"A) Ampere", "B) Volt", "C) Ohm", "D) Watt"}, 'C', 3},
    {"Which organelle is responsible for detoxifying harmful substances in the cell?", "Biology", {"A) Mitochondria", "B) Nucleus", "C) Ribosome", "D) Peroxisome"}, 'D', 3},
    {"What is the largest desert in the world?", "Geography", {"A) Sahara Desert", "B) Gobi Desert", "C) Antarctic Desert", "D) Atacama Desert"}, 'A', 3},
    {"What is the chemical symbol for sodium?", "Chemistry", {"A) Na", "B) Si", "C) So", "D) Se"}, 'A', 3}
};

vector<MCQ> hardQuestions = {
    {"What is the Heisenberg Uncertainty Principle in quantum mechanics? (Physics)", "Physics", {"A) It states that the speed and position of a particle can both be precisely determined simultaneously.", "B) It is impossible to know the exact position and momentum of a particle simultaneously with arbitrary precision.", "C) It defines the behavior of photons in a vacuum.", "D) It is a principle in classical mechanics related to conservation of energy."}, 'B', 4},
    {"What is the integral of e^(-x^2) with respect to x ? (Math)", "Math", {"A) erf(x) + C", "B) sin(x) + C", "C) 1/x + C", "D) There is no elementary integral for this function."}, 'D', 4},
    {"What is the derivative of ln(x) with respect to x? (Math)", "Math", {"A) 1/x", "B) x", "C) -1/x", "D) 0"}, 'A', 4},
    {"Which part of the cell is responsible for protein synthesis? (Biology)", "Biology", {"A) Mitochondria", "B) Nucleus", "C) Ribosome", "D) Golgi apparatus"}, 'C', 4},
    {"In a Young's double-slit experiment, the separation between the slits is d, the wavelength of the light used is λ, and the distance between the slits and the screen is D. What is the condition for observing a dark fringe on the screen? (Physics)", "Physics", {"A) d sin(θ) = mλ", "B) d cos(θ) = mλ", "C) d tan(θ) = mλ", "D) d/λ = mθ"}, 'A', 4},
    {"In nuclear physics, what is the Q-value of a nuclear reaction? (Physics)", "Physics", {"A) The energy required to initiate the reaction.", "B) The energy released or absorbed in the reaction", "C) The quantum state of the particles involved.", "D) The angular momentum of the reaction."}, 'A', 4},
    {"If A and B are two square matrices of the same order, and AB = BA, what can be concluded about A and B? (Math)", "Math", {"A)  A and B are inverses of each other.", "B) A and B commute with each other", "C)  A and B have the same determinant.", "D) A and B have no common properties."}, 'A', 4},
    {"If f(x) = x^3 - 4x^2 + 6x - 8, what are the critical points of the function? (Math)", "Math", {"A) x = 2", "B)  x = 1", "C)  x = 0", "D) x = -2"}, 'A', 4},
    {"Which data structure is best suited for implementing a priority queue? (Programming)", "Programming", {"A) Stack", "B) Linked List", "C) Heap", "D) Queue"}, 'A', 4},
    {"In computer networking, what layer of the OSI model is responsible for routing packets between networks? (Programming)", "Programming", {"A) Network Layer", "B) Data Link Layer", "C) Transport Layer", "D) Presentation Layer"}, 'A', 4},
    {"In a balanced binary search tree, what is the time complexity for finding the maximum element? (Programming)", "Programming", {"A)  O(1)", "B) O(log n)", "C)  O(n)", "D) O(n log n)"}, 'A', 4},
    {"In quantum mechanics, what does the Heisenberg Uncertainty Principle state? (Physics)", "Physics", {"A) It's impossible to know both the position and momentum of a particle with absolute certainty.", "B) The position of a particle can be precisely determined at all times.", "C) Energy and time are completely independent of each other in quantum systems.", "D) Particles can exist in multiple states simultaneously without any limitations."}, 'A', 4},
    {"Which of the following statements is true regarding a singular matrix? (Math)", "Math", {"A) A singular matrix always has an inverse.", "B) A singular matrix has a determinant equal to zero.", "C) A singular matrix is always symmetric.", "D) A singular matrix has no eigenvectors."}, 'A', 4},
    {"In the context of databases, what is a foreign key? (Programming)", "Programming", {"A) A primary key in another table.", "B) A unique identifier for a record in a table.", "C) A key that is automatically generated by the database.", "D) A key used to encrypt data in the database."}, 'A', 4},
    {"What is the purpose of a compiler in programming languages? (Programming)", "Programming", {"A) To execute the program.", "B) To translate high-level code into machine code.", "C) To manage memory allocation for the program.", "D) To debug the code."}, 'A', 4},
    {"What is an 'abstract class' in C++?", "Programming", {"A) A class that cannot be instantiated", "B) A class with only pure virtual functions", "C) A class with a pure virtual destructor", "D) A class with no member variables"}, 'B', 4},
    {"What is the Schrödinger equation in quantum mechanics used for?", "Physics", {"A) Describing the behavior of electromagnetic waves", "B) Predicting the motion of planets", "C) Describing the behavior of subatomic particles", "D) Calculating the speed of light"}, 'C', 4},
    {"What is the smallest unit of life?", "Biology", {"A) Cell", "B) Atom", "C) Molecule", "D) Tissue"}, 'A', 4},
    {"What is the capital of Burkina Faso?", "Geography", {"A) Ouagadougou", "B) Bamako", "C) Niamey", "D) Lome"}, 'A', 4},
    {"What is the atomic number of carbon?", "Chemistry", {"A) 6", "B) 8", "C) 12", "D) 14"}, 'A', 4},
    {"In C++, what is a 'pure virtual function'?", "Programming", {"A) A function that has no implementation", "B) A function that cannot be called", "C) A function that returns a constant value", "D) A function that is declared static"}, 'A', 4},
    {"What is the speed of light in a vacuum?", "Physics", {"A) 299,792,458 meters per second", "B) 3.00 × 10^8 kilometers per hour", "C) 671,000,000 miles per hour", "D) 1,000,000,000 feet per second"}, 'A', 4},
    {"Which blood type is considered the 'universal donor'?", "Biology", {"A) A", "B) B", "C) AB", "D) O"}, 'D', 4},
    {"Which mountain range is the longest in the world?", "Geography", {"A) Himalayas", "B) Rocky Mountains", "C) Andes", "D) Alps"}, 'C', 4},
    {"What is the chemical symbol for mercury?", "Chemistry", {"A) Hg", "B) Me", "C) Me2", "D) Mg"}, 'A', 4},
    {"In C++, what is 'polymorphism' in object-oriented programming?", "Programming", {"A) The ability to have multiple constructors in a class", "B) The ability to have multiple base classes", "C) The ability to have multiple functions with the same name but different parameters", "D) The ability to have multiple private members in a class"}, 'C', 4},
    {"What is the charge of an electron?", "Physics", {"A) Positive", "B) Neutral", "C) Negative", "D) It varies"}, 'C', 4},
    {"What is the main function of the mitochondria in a cell?", "Biology", {"A) DNA replication", "B) Energy production", "C) Synthesizing proteins", "D) Storing genetic information"}, 'B', 4},
    {"Which river is the longest in the world?", "Geography", {"A) Nile", "B) Amazon", "C) Mississippi", "D) Yangtze"}, 'A', 4},
    {"What is the chemical symbol for potassium?", "Chemistry", {"A) Po", "B) Pt", "C) K", "D) Kr"}, 'C', 4},
    {"What is the difference between 'stack' and 'queue' data structures in programming?", "Programming", {"A) Stack uses LIFO (Last-In-First-Out) and Queue uses FIFO (First-In-First-Out)", "B) Stack is used for sorting data, and Queue is used for searching data", "C) Stack is a linear data structure, and Queue is a hierarchical data structure", "D) Stack is faster than Queue in all cases"}, 'A', 4},
    {"What is the Planck constant in physics?", "Physics", {"A) 6.626 x 10^-34 J·s", "B) 9.81 m/s^2", "C) 3 x 10^8 m/s", "D) 1.602 x 10^-19 C"}, 'A', 4},
    {"Which organelle is known as the 'powerhouse of the cell'?", "Biology", {"A) Nucleus", "B) Golgi apparatus", "C) Ribosome", "D) Mitochondria"}, 'D', 4},
    {"Which desert is the largest subtropical desert in the world?", "Geography", {"A) Sahara Desert", "B) Kalahari Desert", "C) Arabian Desert", "D) Sonoran Desert"}, 'A', 4},
    {"What is the chemical symbol for nitrogen?", "Chemistry", {"A) Ne", "B) Nt", "C) Nr", "D) N"}, 'D', 4}
};


        set<int> askedQuestions;
        int score = 0;
        int questionsAttempted = 0;
        int consecutiveFailures = 0;
        int consecutiveSuccesses = 0;

        map<string, pair<int, int>> topicPerformance;
        map<string, int> incorrectTopics;

        cout << "Welcome to the adaptive difficulty quiz!" << endl;

        while (questionsAttempted < 20 && !(currentDifficulty == 4 && hardQuestions.empty())) {
            vector<MCQ>& currentQuestionSet = (currentDifficulty == 1) ? easyQuestions :
                                               (currentDifficulty == 2) ? normalQuestions :
                                               (currentDifficulty == 3) ? mediumQuestions :
                                               hardQuestions;

            int random_index;
            do {
                random_index = rand() % currentQuestionSet.size();
            } while (askedQuestions.count(random_index) > 0);

            askedQuestions.insert(random_index);
            MCQ current_question = currentQuestionSet[random_index];

            displayQuestion(current_question);

            char user_choice = getUserAnswer();

            if (evaluateAnswer(current_question, user_choice)) {
                cout << "Correct!" << endl;
                score++;
                consecutiveFailures = 0;
                consecutiveSuccesses++;

                if (currentDifficulty < 4 && consecutiveSuccesses >= 3) {
                    currentDifficulty++;
                    consecutiveSuccesses = 0;
                }

                topicPerformance[current_question.topic].first++;
                topicPerformance[current_question.topic].second++;
            } else {
                cout << "Incorrect. The correct answer is " << current_question.correct_option << endl;
                consecutiveFailures++;

                if (consecutiveFailures >= 3 && currentDifficulty > 1) {
                    currentDifficulty--;
                    consecutiveFailures = 0;
                }

                incorrectTopics[current_question.topic]++;
            }

            questionsAttempted++;
        }

        printCertificateHeader();
        cout << "  CONGRATULATIONS!" << endl;
        cout << "You have successfully completed the Adaptive Difficulty Quiz." << endl;
        cout << "Total questions attempted: " << questionsAttempted << endl;
        cout << "Total correct answers: " << score << endl;

        cout << "=====================================" << endl;
        cout << "          PERFORMANCE ANALYSIS        " << endl;
        cout << "=====================================" << endl;

        vector<Question> questions = {
            {"Biology", true},
            {"Geography", true},
            {"Math", true},
            {"Maths", true},
            {"Physics", true},
            {"Programming", true},
            {"Astronomy", false},
            {"Biology", false},
            {"Chemistry", false},
            {"Chemistry", false},
            {"Environmental Science", false},
            {"General Knowledge", false},
            {"General Knowledge", false},
            {"General Knowledge", false},
            {"Geography", false},
            {"Math", false},
            {"Physics", false},
            {"Programming", false},
            {"Programming", false}
        };

        std::map<std::string, int> topicTotalCorrect;
        std::map<std::string, int> topicTotalQuestions;
        std::map<std::string, int> topicTotalIncorrect;

        for (const Question& q : questions) {
            if (q.isCorrect) {
                topicTotalCorrect[q.topic]++;
            }
            topicTotalQuestions[q.topic]++;
            if (!q.isCorrect) {
                topicTotalIncorrect[q.topic]++;
            }
        }

        std::cout << "Performance Analysis by Topic:" << std::endl;
        double totalStrongAccuracy = 0.0;
        double totalWeakAccuracy = 100.0; 
        std::string strongSubject = "";
        std::string weakSubject = "";

        for (const auto& entry : topicTotalQuestions) {
            const std::string& topic = entry.first;
            int totalQuestions = entry.second;
            int totalCorrect = topicTotalCorrect[topic];
            int totalIncorrect = topicTotalIncorrect[topic];
            double accuracy = (totalQuestions > 0) ? (static_cast<double>(totalCorrect) / totalQuestions) * 100 : 0.0;

            std::cout << topic << ": " << totalCorrect << " correct out of " << totalQuestions
                      << " (" << accuracy << "%), " << totalIncorrect << " incorrect" << std::endl;

            if (accuracy > totalStrongAccuracy) {
                totalStrongAccuracy = accuracy;
                strongSubject = topic;
            }
            if (accuracy < totalWeakAccuracy) {
                totalWeakAccuracy = accuracy;
                weakSubject = topic;
            }
        }

        std::cout << "Strongest Subject: " << strongSubject << " with " << totalStrongAccuracy << "%" << std::endl;
        std::cout << "Weakest Subject: " << weakSubject << " with " << totalWeakAccuracy << "%" << std::endl;

        printCertificateFooter();

        string retryChoice;
        if (currentDifficulty < maxDifficulty) {
            cout << "Do you want to try again at the next difficulty level? (yes/no): ";
            cin >> retryChoice;
        } else {
            cout << "You have reached the highest difficulty level. Do you want to try again at the same difficulty? (yes/no): ";
            cin >> retryChoice;
        }

        if (retryChoice != "yes") {
            break;
        }
    }

    return 0;
}
