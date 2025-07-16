#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    validate_lexer.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 20:30:00 by jjorda            #+#    #+#              #
#    Updated: 2025/07/16 20:30:00 by jjorda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Test counter
TOTAL_TESTS=0
PASSED_TESTS=0

# Print test header
print_header() {
    echo -e "${BLUE}================================${NC}"
    echo -e "${BLUE}    LEXER VALIDATION TESTS      ${NC}"
    echo -e "${BLUE}================================${NC}"
}

# Print test result
print_test_result() {
    local test_name="$1"
    local result="$2"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    if [ "$result" = "PASS" ]; then
        echo -e "${GREEN}✅ $test_name${NC}"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        echo -e "${RED}❌ $test_name${NC}"
    fi
}

# Test basic word tokenization
test_basic_words() {
    echo -e "\n${YELLOW}Testing basic word tokenization...${NC}"
    
    # Test single word
    echo "echo" | ./test_lexer >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        print_test_result "Single word (echo)" "PASS"
    else
        print_test_result "Single word (echo)" "FAIL"
    fi
    
    # Test multiple words
    echo "echo hello world" | ./test_lexer >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        print_test_result "Multiple words (echo hello world)" "PASS"
    else
        print_test_result "Multiple words (echo hello world)" "FAIL"
    fi
}

# Test operators
test_operators() {
    echo -e "\n${YELLOW}Testing operators...${NC}"
    
    # Test pipe
    echo "ls | grep" | ./test_lexer >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        print_test_result "Pipe operator (ls | grep)" "PASS"
    else
        print_test_result "Pipe operator (ls | grep)" "FAIL"
    fi
    
    # Test redirections
    echo "echo hello > file" | ./test_lexer >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        print_test_result "Output redirection (> file)" "PASS"
    else
        print_test_result "Output redirection (> file)" "FAIL"
    fi
    
    echo "cat < file" | ./test_lexer >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        print_test_result "Input redirection (< file)" "PASS"
    else
        print_test_result "Input redirection (< file)" "FAIL"
    fi
}

# Test whitespace handling
test_whitespace() {
    echo -e "\n${YELLOW}Testing whitespace handling...${NC}"
    
    # Test multiple spaces
    echo "  echo    hello   " | ./test_lexer >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        print_test_result "Multiple spaces" "PASS"
    else
        print_test_result "Multiple spaces" "FAIL"
    fi
    
    # Test tabs and spaces mix
    echo -e "\techo\t\thello\t" | ./test_lexer >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        print_test_result "Tabs and spaces" "PASS"
    else
        print_test_result "Tabs and spaces" "FAIL"
    fi
}

# Test complex combinations
test_complex() {
    echo -e "\n${YELLOW}Testing complex combinations...${NC}"
    
    # Test pipe with redirections
    echo "ls | grep test > output" | ./test_lexer >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        print_test_result "Pipe with redirection" "PASS"
    else
        print_test_result "Pipe with redirection" "FAIL"
    fi
    
    # Test multiple pipes
    echo "ls | grep txt | wc -l" | ./test_lexer >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        print_test_result "Multiple pipes" "PASS"
    else
        print_test_result "Multiple pipes" "FAIL"
    fi
}

# Test edge cases
test_edge_cases() {
    echo -e "\n${YELLOW}Testing edge cases...${NC}"
    
    # Test empty string
    echo "" | ./test_lexer >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        print_test_result "Empty string" "PASS"
    else
        print_test_result "Empty string" "FAIL"
    fi
    
    # Test only spaces
    echo "   " | ./test_lexer >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        print_test_result "Only spaces" "PASS"
    else
        print_test_result "Only spaces" "FAIL"
    fi
}

# Test memory management
test_memory() {
    echo -e "\n${YELLOW}Testing memory management...${NC}"
    
    # Test with valgrind if available
    if command -v valgrind >/dev/null 2>&1; then
        echo "echo hello | grep test" | valgrind --leak-check=full --error-exitcode=1 ./test_lexer >/dev/null 2>&1
        if [ $? -eq 0 ]; then
            print_test_result "Memory leaks check" "PASS"
        else
            print_test_result "Memory leaks check" "FAIL"
        fi
    else
        echo -e "${YELLOW}Valgrind not available, skipping memory test${NC}"
        print_test_result "Memory leaks check" "SKIP"
    fi
}

# Print final results
print_summary() {
    echo -e "\n${BLUE}================================${NC}"
    echo -e "${BLUE}         TEST SUMMARY           ${NC}"
    echo -e "${BLUE}================================${NC}"
    echo -e "Total tests: $TOTAL_TESTS"
    echo -e "Passed: ${GREEN}$PASSED_TESTS${NC}"
    echo -e "Failed: ${RED}$((TOTAL_TESTS - PASSED_TESTS))${NC}"
    
    if [ $PASSED_TESTS -eq $TOTAL_TESTS ]; then
        echo -e "\n${GREEN}🎉 All tests passed! Lexer Phase 2 is ready.${NC}"
        exit 0
    else
        echo -e "\n${RED}⚠️  Some tests failed. Please review the implementation.${NC}"
        exit 1
    fi
}

# Main execution
main() {
    # Check if test_lexer exists
    if [ ! -f "./test_lexer" ]; then
        echo -e "${RED}Error: test_lexer executable not found.${NC}"
        echo -e "${YELLOW}Please run: make test_lexer${NC}"
        exit 1
    fi
    
    print_header
    test_basic_words
    test_operators
    test_whitespace
    test_complex
    test_edge_cases
    test_memory
    print_summary
}

# Run main function
main "$@"
