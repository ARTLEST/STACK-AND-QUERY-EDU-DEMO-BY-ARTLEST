/*
 * Educational Stack Data Structure Demonstration
 * 
 * This educational implementation demonstrates fundamental stack concepts including
 * LIFO (Last In, First Out) operations, stack queries, and practical applications.
 * The system provides clear learning examples with step-by-step explanations
 * suitable for computer science education and programming instruction.
 * 
 * Learning Objectives:
 * - Understanding stack data structure fundamentals
 * - Implementing basic stack operations (push, pop, peek)
 * - Analyzing stack behavior and properties
 * - Applying stack concepts in practical scenarios
 * 
 * Target Platform: Educational environments and online compilers
 * Execution Model: Fixed demonstration sequence for consistent learning
 * Code hints and optimizations by artlest
 */

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

// Educational constants for demonstration control
const int DEMONSTRATION_STEPS = 20;
const int LEARNING_EXAMPLES = 8;
const int DISPLAY_WIDTH = 55;

// Function prototypes for educational modules
void display_educational_header();
void explain_stack_concepts();
void demonstrate_basic_operations(std::stack<int>& learning_stack);
void perform_educational_push(std::stack<int>& stack_example, int value, int step_number);
void perform_educational_pop(std::stack<int>& stack_example, int step_number);
void demonstrate_stack_queries(const std::stack<int>& stack_example);
void visualize_stack_structure(std::stack<int> stack_copy);
void show_practical_applications();
void demonstrate_stack_scenarios();
void display_learning_summary();

int main() {
    // Initialize educational demonstration environment
    std::stack<int> educational_stack;
    
    // Display learning introduction
    display_educational_header();
    
    // Explain fundamental stack concepts
    explain_stack_concepts();
    
    // Demonstrate basic stack operations
    demonstrate_basic_operations(educational_stack);
    
    // Show practical stack scenarios
    demonstrate_stack_scenarios();
    
    // Display educational summary
    display_learning_summary();
    
    return 0; // Educational demonstration completion
}

// Educational function implementations

void display_educational_header() {
    // Display engaging educational introduction
    std::cout << std::string(DISPLAY_WIDTH, '=') << std::endl;
    std::cout << std::setw(35) << "STACK DATA STRUCTURE TUTORIAL" << std::endl;
    std::cout << std::setw(30) << "Interactive Learning Demo" << std::endl;
    std::cout << std::string(DISPLAY_WIDTH, '=') << std::endl;
    
    std::cout << "\nWelcome to the Stack Learning Experience!" << std::endl;
    std::cout << "This demonstration teaches stack fundamentals through" << std::endl;
    std::cout << "hands-on examples and interactive visualizations." << std::endl;
}

void explain_stack_concepts() {
    // Provide foundational stack theory explanation
    std::cout << "\n" << std::string(DISPLAY_WIDTH, '-') << std::endl;
    std::cout << "LESSON 1: Understanding Stack Fundamentals" << std::endl;
    std::cout << std::string(DISPLAY_WIDTH, '-') << std::endl;
    
    std::cout << "\nA STACK is a linear data structure that follows the" << std::endl;
    std::cout << "LIFO principle: Last In, First Out" << std::endl;
    
    std::cout << "\nThink of a stack like a pile of plates:" << std::endl;
    std::cout << "- The last plate placed goes on TOP" << std::endl;
    std::cout << "- The first plate removed comes from the TOP" << std::endl;
    std::cout << "- The bottom plates remain until upper ones are removed" << std::endl;
    
    std::cout << "\nPrimary Stack Operations:" << std::endl;
    std::cout << "1. PUSH: Add element to the top" << std::endl;
    std::cout << "2. POP:  Remove element from the top" << std::endl;
    std::cout << "3. TOP:  View the top element (without removing)" << std::endl;
    std::cout << "4. EMPTY: Check if stack contains elements" << std::endl;
    std::cout << "5. SIZE: Count total elements in stack" << std::endl;
}

void demonstrate_basic_operations(std::stack<int>& learning_stack) {
    // Execute step-by-step stack operation demonstrations
    std::cout << "\n" << std::string(DISPLAY_WIDTH, '-') << std::endl;
    std::cout << "LESSON 2: Stack Operations in Action" << std::endl;
    std::cout << std::string(DISPLAY_WIDTH, '-') << std::endl;
    
    std::cout << "\nLet's build a stack with numbers and observe the behavior:" << std::endl;
    
    // Demonstrate push operations with educational explanations
    int demonstration_values[] = {10, 25, 7, 33, 18, 42, 9, 15};
    
    for (int step = 0; step < LEARNING_EXAMPLES; step++) {
        perform_educational_push(learning_stack, demonstration_values[step], step + 1);
        
        // Show intermediate stack state for learning
        if ((step + 1) % 3 == 0) {
            std::cout << "\n--- Learning Checkpoint ---" << std::endl;
            visualize_stack_structure(learning_stack);
            demonstrate_stack_queries(learning_stack);
        }
    }
    
    std::cout << "\nNow let's demonstrate POP operations:" << std::endl;
    
    // Demonstrate pop operations with educational context
    for (int pop_step = 1; pop_step <= 4; pop_step++) {
        perform_educational_pop(learning_stack, pop_step);
        
        // Show how stack changes after each pop
        if (pop_step % 2 == 0) {
            visualize_stack_structure(learning_stack);
        }
    }
}

void perform_educational_push(std::stack<int>& stack_example, int value, int step_number) {
    // Execute push operation with detailed educational explanation
    std::cout << "\nStep " << step_number << ": PUSH(" << value << ")" << std::endl;
    
    // Show stack state before operation
    std::cout << "  Before: Stack size = " << stack_example.size() << std::endl;
    
    // Execute the push operation
    stack_example.push(value);
    
    // Explain what happened
    std::cout << "  Action: Adding " << value << " to the TOP of the stack" << std::endl;
    std::cout << "  After:  Stack size = " << stack_example.size() << std::endl;
    std::cout << "  Result: " << value << " is now the topmost element" << std::endl;
}

void perform_educational_pop(std::stack<int>& stack_example, int step_number) {
    // Execute pop operation with educational explanation
    if (stack_example.empty()) {
        std::cout << "\nStep " << step_number << ": POP() - CANNOT EXECUTE" << std::endl;
        std::cout << "  Error: Stack is empty (Stack Underflow)" << std::endl;
        std::cout << "  Lesson: Always check if stack is empty before popping!" << std::endl;
        return;
    }
    
    std::cout << "\nStep " << step_number << ": POP()" << std::endl;
    
    // Show element being removed
    int removed_value = stack_example.top();
    std::cout << "  Before: Top element = " << removed_value << ", Size = " << stack_example.size() << std::endl;
    
    // Execute the pop operation
    stack_example.pop();
    
    // Explain the result
    std::cout << "  Action: Removing " << removed_value << " from the TOP" << std::endl;
    std::cout << "  After:  Size = " << stack_example.size() << std::endl;
    
    if (!stack_example.empty()) {
        std::cout << "  Result: " << stack_example.top() << " is now the new top element" << std::endl;
    } else {
        std::cout << "  Result: Stack is now EMPTY" << std::endl;
    }
}

void demonstrate_stack_queries(const std::stack<int>& stack_example) {
    // Show various ways to query stack information
    std::cout << "\n>> Stack Query Information:" << std::endl;
    
    // Check if stack is empty
    if (stack_example.empty()) {
        std::cout << "   Status: EMPTY stack (no elements)" << std::endl;
    } else {
        std::cout << "   Status: ACTIVE stack (contains elements)" << std::endl;
        std::cout << "   Top Element: " << stack_example.top() << std::endl;
    }
    
    std::cout << "   Total Elements: " << stack_example.size() << std::endl;
    
    // Educational note about stack limitations
    std::cout << "   Note: We can only access the TOP element directly!" << std::endl;
}

void visualize_stack_structure(std::stack<int> stack_copy) {
    // Create visual representation of stack structure
    std::cout << "\n>> Visual Stack Representation:" << std::endl;
    
    if (stack_copy.empty()) {
        std::cout << "   |     |  <- Empty stack" << std::endl;
        std::cout << "   +-----+" << std::endl;
        return;
    }
    
    // Build visual stack from top to bottom
    std::vector<int> elements_for_display;
    while (!stack_copy.empty()) {
        elements_for_display.push_back(stack_copy.top());
        stack_copy.pop();
    }
    
    // Display stack elements vertically (top to bottom)
    std::cout << "   +-----+" << std::endl;
    for (size_t i = 0; i < elements_for_display.size(); i++) {
        std::cout << "   | " << std::setw(3) << elements_for_display[i] << " |";
        if (i == 0) {
            std::cout << " <- TOP (last added, first to remove)";
        }
        std::cout << std::endl;
    }
    std::cout << "   +-----+" << std::endl;
    std::cout << "   Bottom" << std::endl;
}

void demonstrate_stack_scenarios() {
    // Show real-world applications and scenarios
    std::cout << "\n" << std::string(DISPLAY_WIDTH, '-') << std::endl;
    std::cout << "LESSON 3: Stack Applications and Scenarios" << std::endl;
    std::cout << std::string(DISPLAY_WIDTH, '-') << std::endl;
    
    show_practical_applications();
    
    // Demonstrate a simple bracket matching scenario
    std::cout << "\nPractical Example: Parentheses Matching" << std::endl;
    std::cout << "Expression: ((5 + 3) * (7 - 2))" << std::endl;
    
    std::stack<char> bracket_stack;
    std::string expression = "((5+3)*(7-2))";
    
    std::cout << "\nTracing through the expression:" << std::endl;
    for (size_t i = 0; i < expression.length(); i++) {
        char current_char = expression[i];
        
        if (current_char == '(') {
            bracket_stack.push(current_char);
            std::cout << "Found '(' - PUSH to stack. Stack size: " << bracket_stack.size() << std::endl;
        } else if (current_char == ')') {
            if (!bracket_stack.empty()) {
                bracket_stack.pop();
                std::cout << "Found ')' - POP from stack. Stack size: " << bracket_stack.size() << std::endl;
            }
        }
    }
    
    if (bracket_stack.empty()) {
        std::cout << "Result: All parentheses are properly matched!" << std::endl;
    } else {
        std::cout << "Result: Unmatched parentheses detected!" << std::endl;
    }
}

void show_practical_applications() {
    // Explain real-world uses of stacks
    std::cout << "\nReal-World Stack Applications:" << std::endl;
    
    std::cout << "\n1. Function Call Management:" << std::endl;
    std::cout << "   - Program tracks function calls in execution stack" << std::endl;
    std::cout << "   - When function finishes, program returns to caller" << std::endl;
    
    std::cout << "\n2. Undo Operations:" << std::endl;
    std::cout << "   - Text editors store previous states" << std::endl;
    std::cout << "   - Ctrl+Z removes the most recent change" << std::endl;
    
    std::cout << "\n3. Browser History:" << std::endl;
    std::cout << "   - Back button returns to previous page" << std::endl;
    std::cout << "   - Most recent page is first to be revisited" << std::endl;
    
    std::cout << "\n4. Expression Evaluation:" << std::endl;
    std::cout << "   - Mathematical expressions use stacks" << std::endl;
    std::cout << "   - Parentheses matching and operator precedence" << std::endl;
    
    std::cout << "\n5. Memory Management:" << std::endl;
    std::cout << "   - Program variables stored in call stack" << std::endl;
    std::cout << "   - Local variables created and destroyed automatically" << std::endl;
}

void display_learning_summary() {
    // Provide comprehensive learning recap
    std::cout << "\n" << std::string(DISPLAY_WIDTH, '=') << std::endl;
    std::cout << "EDUCATIONAL SUMMARY: Key Learning Points" << std::endl;
    std::cout << std::string(DISPLAY_WIDTH, '=') << std::endl;
    
    std::cout << "\nWhat the student has learned about stacks:" << std::endl;
    
    std::cout << "\n✓ Stack Definition:" << std::endl;
    std::cout << "  LIFO data structure - Last In, First Out" << std::endl;
    
    std::cout << "\n✓ Core Operations:" << std::endl;
    std::cout << "  PUSH: Add element to top" << std::endl;
    std::cout << "  POP:  Remove element from top" << std::endl;
    std::cout << "  TOP:  Access top element without removal" << std::endl;
    
    std::cout << "\n✓ Important Properties:" << std::endl;
    std::cout << "  - Only top element is directly accessible" << std::endl;
    std::cout << "  - Stack can be empty (underflow risk)" << std::endl;
    std::cout << "  - Elements are processed in reverse order" << std::endl;
    
    std::cout << "\n✓ Practical Applications:" << std::endl;
    std::cout << "  - Function call management" << std::endl;
    std::cout << "  - Undo operations in software" << std::endl;
    std::cout << "  - Expression evaluation and parsing" << std::endl;
    
    std::cout << "\n✓ Programming Best Practices:" << std::endl;
    std::cout << "  - Always check for empty stack before popping" << std::endl;
    std::cout << "  - Use appropriate data types for stack elements" << std::endl;
    std::cout << "  - Consider stack size limitations in applications" << std::endl;
    
    std::cout << "\n" << std::string(DISPLAY_WIDTH, '=') << std::endl;
    std::cout << "Educational demonstration completed successfully!" << std::endl;
    std::cout << "The student now understands fundamental stack concepts." << std::endl;
    std::cout << std::string(DISPLAY_WIDTH, '=') << std::endl;
}