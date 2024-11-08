#pragma once

#include "StrucData.h"

class MCQ

// Add question to linked list
void addQuestion(PTRQUESTION& questionList, const Question& question);

// Print all questions
void printQuestions(const PTRQUESTION& questionList);

// Delete question by question ID
bool deleteQuestion(PTRQUESTION& questionList, int questionId);

// Edit info of question
bool editQuestion(PTRQUESTION& questionList, int questionId, const Question& updatedInfo);

// Find question by ID
PTRQUESTION findQuestion(PTRQUESTION questionList, int questionId);

// Save questions to file
void saveQuestionsToFile(const PTRQUESTION& questionList, const std::string& fileName);

// Load questions from file
void loadQuestionsFromFile(PTRQUESTION& questionList, const std::string& fileName);

// Paginate questions
void paginateQuestions(const PTRQUESTION& questionList, int page, int pageSize);
