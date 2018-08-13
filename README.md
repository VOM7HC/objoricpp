# objoricpp
Object orientation programming with Visual CPlusPlus, Example with Patient and Virus. Note: Please DON'T "COPYCAT" it, you must do this excercise yourself, this code is just a reference

1. Virus:

a. Attributes: 
- char* m_dna: to store the order of acid nucleic sequence (A, T, G, X), read from file (using C++ file text reader).
- int m_resistance: the virus resistance ability (10 – 30)

b. Methods: 
- Constructor
- Destructor
- Copy Constructor
- LoadADNInformation() : Load DNA information from a ATGX.bin and store it in m_dna. (Only load the information in ATGX and store m_dna, it just a sequence and has no special structure).
- ReduceResistance(medicine_resistance): when a Patient call TakeMedicine, the medicine has the medicine_resistance and it will reduce the resistance of virus. If m_resistance of virus <= 0, the virus was destroyed. The implementing of ReduceResistance is m_resistance = m_resistance – medicine_resistance;
   - Medicine_resistance will be input from Patient when he take medicine (it is mentioned in Patient class. (When patient take medicine, the medicine has its resistance, the medicine resistance help patient reduce the virus resistance). 
Virus is an abstract class with pure virtual function as bellow: 
- DoBorn: This function represent the virus was born. It should be call in Constructor in derive class).
- DoClone: This function represents the new virus that all its attributes are copied to a new one. DoClone will return a virus cloned from it. This function can return a Pointer / List of cloned viruses.
- DoDie: This function represent that the virus was die. It should be call in the Destructor in derive class).
- InitResistance: this function will initialize the resistance (m_resistance) of virus to medicine and store it in m_resistance, this method should call in the Constructor of derive class.

2. Flu virus (Inherit Virus)

a. Attributes: 
- int m_color: the color of Flu virus is blue (value 0x0000ff) or red (value 0xff0000)

b. Methods, override pure virtual function of Virus 
- DoBorn: Call LoadADNInformation() and randomly initialize Flu m_color.
- DoClone: This function represents a new virus that all its attributes are copied to a new one. DoClone will return a virus that cloned from it. This function can return a Pointer/ /List of cloned viruses.
- DoDie: release all virus data.
- InitResistance: Set value for m_resistance. Random from 10 – 20 for red Flu virus and 10 – 15 for blue Flu virus. Call it from constructor.

3. Dengue virus (Inherit Virus)

a. Attributes: 
- char m_protein[4]: protein in virus represent the type of Dengue virus.

b. Methods, override pure virtual function of Virus:
- DoBorn: Call LoadADNInformation() and randomly initialize protein for Dengue Virus (value NS3, NS5, E).
- DoClone: This function presents virus that all its attributes are copied to new viruses. Different to DoClone in FluVirus, this function will return 2 new viruses.
- DoDie: release all virus data.
- InitResistance: this function will initialize the resistance (m_resistance) of virus to medicine and store it in m_resistance, this method should call in the Constructor of derive class. Random from 1 – 10 for NS3 protein, 11-20 for NS5 protein and 21-30 for E protein.

4. Patient:

a. Attributes: 
- int m_resistance: his natural resistance.
- list<Virus*> m_virusList: The current virus in his body.
- int m_state: 0 – DIE, 1 - ALIVE

b. Methods, override pure virtual function of Virus:
- Constructor
- Destructor
- InitResistance: Randomly initialize the resistance of Patient (1000-9000). Call it in Constructor.
- DoStart: Initialize all virus randomly (around 10 – 20 virus) and add them to m_virusList. Call it in Constructor. Set m_state = 1
- TakeMedicine: Iterator virus list and the virus will call the ReduceResistance(medicine_resistance), the medicine_resistance random from 1 to 60.
    - If the virus does not die after taking medicine, it will be cloned and add them to m_virusList, if not remove the virus from list.
    - If the m_resistance of Patient is less than the total virus resistance in m_virusList. Patient DoDie.
- DoDie: Release all resources (m_virusList). Set m_state = 0
- GetState: return m_state
