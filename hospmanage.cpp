#include <iostream>
#include <string>

using namespace std;

class node {
public:
    string patient;
    string sex;
    string medicalCondition;
    node* next;
    int age;

    node(int age, string patient, string sex, string medicalCondition) {
        this->age = age;
        this->medicalCondition = medicalCondition;
        this->patient = patient;
        this->sex = sex;
        this->next = NULL;
    }
};

class node2 {
public:
    string doctor;
    node2* next2;

    node2(string doctor) {
        this->doctor = doctor;
        this->next2 = NULL;
    }


    void insertDoctor(node2*& head1, string doctor) {
        node2* temp = new node2(doctor);
        temp->next2 = head1;
        head1 = temp;
    }


    void displayDoctors(node2* head1) {
        node2* temp = head1;
        while (temp != NULL) {
            cout << "Doctor: " << temp->doctor << endl;
            temp = temp->next2;
        }
    }


    node2* findDoctor(node2* head1, string doctor) {
        node2* temp = head1;
        while (temp != NULL) {
            if (temp->doctor == doctor) {
                return temp;
            }
            temp = temp->next2;
        }
        return NULL;
    }


    void removeDoctor(node2*& head1, string doctor) {
        if (head1 == NULL) {
            cout << "No doctors available!" << endl;
            return;
        }

        node2* temp = head1;
        node2* prev = NULL;

        while (temp != NULL && temp->doctor != doctor) {
            prev = temp;
            temp = temp->next2;
        }

        if (temp == NULL) {
            cout << "Doctor not found!" << endl;
            return;
        }

        if (prev == NULL) {
            head1 = temp->next2;
        } else {
            prev->next2 = temp->next2;
        }

        delete temp;
        cout << "Doctor removed: " << doctor << endl;
    }
};

class node3 {
public:
    string patient;
    string doctor;
    string time;
    node3* next3;

    node3(string patient, string doctor, string time) {
        this->patient = patient;
        this->doctor = doctor;
        this->time = time;
        this->next3 = NULL;
    }
};

class PatientQueue {
public:
    node* front;
    node* rear;

    PatientQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(string patient, string sex, string medicalCondition, int age) {
        node* temp = new node(age, patient, sex, medicalCondition);
        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << "Patient added to queue: " << patient << endl;
    }

    node* dequeue() {
        if (front == NULL) {
            cout << "No patients in queue!" << endl;
            return NULL;
        }
        node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        return temp;
    }

    void displayQueue() {
        if (front == NULL) {
            cout << "No patients in queue." << endl;
            return;
        }
        node* temp = front;
        while (temp != NULL) {
            cout << "Patient in Queue: " << temp->patient << ", Age: " << temp->age << endl;
            temp = temp->next;
        }
    }

    node* findPatient(string patientName) {
        node* temp = front;
        while (temp != NULL) {
            if (temp->patient == patientName) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void removePatient(string patientName) {
        if (front == NULL) {
            cout << "No patients in queue!" << endl;
            return;
        }

        node* temp = front;
        node* prev = NULL;

        while (temp != NULL && temp->patient != patientName) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Patient not found!" << endl;
            return;
        }

        if (prev == NULL) {
            front = temp->next;
        } else {
            prev->next = temp->next;
        }

        if (temp == rear) {
            rear = prev;
        }

        delete temp;
        cout << "Patient removed from queue: " << patientName << endl;
    }

    void displayPatientInfo(string patientName) {
        node* temp = findPatient(patientName);
        if (temp != NULL) {
            cout << "Patient Name: " << temp->patient << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Sex: " << temp->sex << endl;
            cout << "Medical Condition: " << temp->medicalCondition << endl;
        } else {
            cout << "Patient not found!" << endl;
        }
    }
};

class AppointmentQueue {
public:
    node3* front;
    node3* rear;

    AppointmentQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(string patient, string doctor, string time) {
        node3* temp = new node3(patient, doctor, time);
        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next3 = temp;
            rear = temp;
        }
        cout << "Appointment scheduled for Patient: " << patient << " with Doctor: " << doctor << " at " << time << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "No appointments to process!" << endl;
            return;
        }
        node3* temp = front;
        front = front->next3;
        if (front == NULL) {
            rear = NULL;
        }
        cout << "Processed Appointment - Patient: " << temp->patient << " with Doctor: " << temp->doctor << " at " << temp->time << endl;
        delete temp;
    }

    void displayAppointments() {
        if (front == NULL) {
            cout << "No appointments scheduled." << endl;
            return;
        }
        node3* temp = front;
        while (temp != NULL) {
            cout << "Appointment - Patient: " << temp->patient << ", Doctor: " << temp->doctor << ", Time: " << temp->time << endl;
            temp = temp->next3;
        }
    }
};

int main() {
    PatientQueue patientQueue;
    node2* doctorHead = NULL;
    AppointmentQueue appointmentQueue;

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add Patient to Queue" << endl;
        cout << "2. Remove Patient from Queue" << endl;
        cout << "3. Display Patient Info" << endl;
        cout << "4. Manage Doctors" << endl;
        cout << "5. Schedule Appointments (Automatically uses next patient in queue)" << endl;
        cout << "6. Process Appointments" << endl;
        cout << "7. Display All Appointments" << endl;
        cout << "8. Display Patients in Queue" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string patient, sex, medicalCondition;
                int age;
                cout << "Enter Patient Name: ";
                getline(cin, patient);
                cout << "Enter Patient Sex: ";
                getline(cin, sex);
                cout << "Enter Patient Medical Condition: ";
                getline(cin, medicalCondition);
                cout << "Enter Patient Age: ";
                cin >> age;
                patientQueue.enqueue(patient, sex, medicalCondition, age);
                cin.ignore();
                break;
            }

            case 2: {
                string patientName;
                cout << "Enter Patient Name to Remove: ";
                getline(cin, patientName);
                patientQueue.removePatient(patientName);
                break;
            }

            case 3: {
                string patientName;
                cout << "Enter Patient Name to Display Info: ";
                getline(cin, patientName);
                patientQueue.displayPatientInfo(patientName);
                break;
            }

            case 4: {
                int doctorChoice;
                string doctor;
                cout << "Manage Doctors:" << endl;
                cout << "1. Add Doctor" << endl;
                cout << "2. Display Doctors" << endl;
                cout << "3. Remove Doctor" << endl;
                cout << "Enter your choice: ";
                cin >> doctorChoice;
                cin.ignore();

                switch (doctorChoice) {
                    case 1:
                        cout << "Enter Doctor Name: ";
                        getline(cin, doctor);
                        doctorHead->insertDoctor(doctorHead, doctor);
                        break;
                    case 2:
                        cout << "Doctors List:" << endl;
                        doctorHead->displayDoctors(doctorHead);
                        break;
                    case 3:  // New case for removing doctor
                        cout << "Enter Doctor Name to Remove: ";
                        getline(cin, doctor);
                        doctorHead->removeDoctor(doctorHead, doctor);
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                }
                break;
            }

            case 5: {
                string doctorName, appointmentTime;

                cout << "Enter Doctor Name: ";
                getline(cin, doctorName);


                node2* doctorNode = doctorHead->findDoctor(doctorHead, doctorName);
                if (doctorNode == NULL) {
                    cout << "Doctor not found!" << endl;
                    break;
                }

                cout << "Enter Appointment Time: ";
                getline(cin, appointmentTime);


                node* nextPatient = patientQueue.dequeue();
                if (nextPatient == NULL) {
                    cout << "No patients in queue!" << endl;
                    break;
                }


                appointmentQueue.enqueue(nextPatient->patient, doctorNode->doctor, appointmentTime);
                break;
            }

            case 6:
                cout << "Processing next appointment..." << endl;
                appointmentQueue.dequeue();
                break;

            case 7:
                cout << "Displaying all scheduled appointments..." << endl;
                appointmentQueue.displayAppointments();
                break;

            case 8:
                cout << "Displaying patients in queue..." << endl;
                patientQueue.displayQueue();
                break;

            case 9:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}

