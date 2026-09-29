# Job Application Management System

A C++ OOP and DSA-based console application for managing and tracking job applications efficiently.

## Overview

The Job Application Management System allows users to maintain job application records and perform operations such as adding, searching, updating, deleting, sorting, and filtering applications.

The project demonstrates practical implementation of **Object-Oriented Programming (OOP)** and **Data Structures & Algorithms (DSA)** concepts using C++.

## Features

- Add new job applications
- View all applications
- Search applications by ID
- Update application status
- Delete applications
- Sort applications by:
  - Company name
  - Priority
- Filter applications by status:
  - Applied
  - OA
  - Interview
  - Rejected
  - Selected
- Display application statistics
- Save applications to a file
- Load applications from a file
- Persistent data storage using a text file

## Technologies Used

- C++
- C++17
- Object-Oriented Programming
- STL (`vector`, `map`, `algorithm`)
- File Handling
- Data Structures & Algorithms

## OOP Concepts Used

- Classes and Objects
- Encapsulation
- Constructors
- Member Functions
- Separation of Interface and Implementation

## Data Structures & Algorithms

- `vector` for storing application records
- Linear search for finding applications by ID
- STL sorting algorithms
- Filtering using iteration
- `map` for application statistics
- File I/O for persistent storage

## Project Structure

```text
JobApplicationManagementSystem/
│
├── main.cpp
├── JobApplication.h
├── JobApplication.cpp
├── ApplicationManager.h
├── ApplicationManager.cpp
├── applications.txt
├── .gitignore
└── README.md
