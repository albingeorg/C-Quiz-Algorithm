# C-Quiz-Algorithm
Levelling Up Algorithm:

User Input and Validation:

The algorithm begins by collecting the user's answer choice (A, B, C, or D) and converts it to uppercase for uniformity.
Checking Answer Correctness:

The algorithm checks whether the user's choice matches the correct option of the current question (current-question.correct_option).
Handling Correct Answers:

If the user's answer is correct:
The algorithm acknowledges with a "Correct" message.
Increases the user's score (score).
Resets the consecutive failure count (consecutiveFailures) to 0.
Checks if the user has achieved three consecutive correct answers and whether the question's difficulty is less than 4. If both conditions are met, the algorithm increases the difficulty by 1.
Updates the topic performance by locating the current question's topic in a map, incrementing both the number of correct answers (first) and the total number of attempts (second).
Handling Incorrect Answers:

If the user's answer is incorrect:
The algorithm provides feedback by printing "Incorrect" and showing the correct answer.
Increments the consecutive failure count (consecutiveFailures) to track consecutive incorrect questions.
If the user has achieved three consecutive correct answers and the question's difficulty is less than 1, the algorithm lowers the difficulty by 1.
Increases the counter for questions attempted (questionsAttempted) to keep track of the total number of questions answered.
Analysis Algorithm:

Data Preparation:

Start with a structured dataset: a vector (std::vector) of Question structures, each containing information about the topic and whether the answer is correct.
Calculating Topic Performance:

Iterate through the dataset, extracting the topic and correctness values for each question.
Recording Correct and Incorrect Answers:

Maintain three maps: one to calculate the total number of correct answers for each topic (topictotalCorrect), one to store the total number of incorrect answers for each topic (topictotalIncorrect), and one to calculate the total number of questions attempted for each topic (topictotalQuestions).
Calculating Topic Metrics:

Using a loop, calculate the following metrics for each topic:
Total number of correct answers for that topic.
Total number of questions attempted on that topic.
Total number of incorrect answers for that topic.
Calculate the accuracy percentage (the percentage of correct answers) for that topic.
Identifying Strongest and Weakest Subjects:

Determine which topics have the highest and lowest accuracy percentages. These topics are considered the "strongest" and "weakest" subjects, respectively.
