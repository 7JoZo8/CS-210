# CS-210

Project Summary and Problem Solved
The idea of this project was to develop an interactive investment calculator application for Airgead Banking, designed to teach users, especially students, the concepts of fiscal responsibility and compound interest. The program allows users to input an initial investment, monthly deposits, an annual interest rate, and the number of years to invest. It then calculates and displays the year-end balances and earned interest with and without monthly deposits, showing how investments grow over time.

What I Did Well
I implemented a clear, object-oriented design with the Banking class encapsulating all data and calculation logic. The program validates user, preventing invalid or negative values. I also included detailed console output formatting to make the results easy to read and understand and I included inline comments throughout the code improve readability and maintainability.

Areas for Improvement
The program could be enhanced by adding input error handling that doesn’t restart the entire input process after a single mistake, improving user experience. Additionally, implementing more advanced input validation and securing against potential buffer overflow issues.

Most Challenging Parts and How I Overcame Them
Calculating compound interest accurately on a monthly basis while displaying yearly summaries was challenging, especially ensuring the interest calculations compounded correctly within loops. I used online resources on finance formulas and tested small snippets to validate calculations before integrating them.

Transferable Skills
This project reinforced skills in object-oriented programming, user input validation, exception handling, and formatted console output—all transferable to many programming tasks. Writing modular, readable code with comments also strengthens professional coding habits useful across software development.

Maintainability, Readability, and Adaptability
I made the program maintainable by organizing related data and functions within a class, using clear naming conventions, and providing inline comments. Readability was prioritized with consistent formatting and simple logic flow. Adaptability is supported through the class design, allowing future extension to add features like different interest compounding methods or GUI integration without major rewrites.
