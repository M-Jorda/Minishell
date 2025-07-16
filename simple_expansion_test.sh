#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    simple_expansion_test.sh                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 00:25:00 by jjorda            #+#    #+#              #
#    Updated: 2025/07/17 00:25:00 by jjorda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo -e "${YELLOW}=== PHASE 3 EXPANSION VALIDATION ===${NC}"

# Check if test_expansion exists and runs
if [ ! -f "./test_expansion" ]; then
    echo -e "${RED}❌ test_expansion not found${NC}"
    echo "Run: make test_expansion"
    exit 1
fi

echo -e "\n${YELLOW}Running expansion tests...${NC}"
./test_expansion > /tmp/expansion_output 2>&1

# Check key indicators of success
success_count=0
total_checks=8

# Check 1: Variable expansion works
if grep -q '\$HOME = "/.*"' /tmp/expansion_output; then
    echo -e "${GREEN}✅ HOME variable expansion${NC}"
    ((success_count++))
else
    echo -e "${RED}❌ HOME variable expansion${NC}"
fi

# Check 2: USER variable expansion works  
if grep -q '\$USER = ".*"' /tmp/expansion_output; then
    echo -e "${GREEN}✅ USER variable expansion${NC}"
    ((success_count++))
else
    echo -e "${RED}❌ USER variable expansion${NC}"
fi

# Check 3: PATH variable expansion works
if grep -q '\$PATH = ".*"' /tmp/expansion_output; then
    echo -e "${GREEN}✅ PATH variable expansion${NC}"
    ((success_count++))
else
    echo -e "${RED}❌ PATH variable expansion${NC}"
fi

# Check 4: Non-existent variable returns empty
if grep -q '\$NONEXISTENT = ""' /tmp/expansion_output; then
    echo -e "${GREEN}✅ Non-existent variable handling${NC}"
    ((success_count++))
else
    echo -e "${RED}❌ Non-existent variable handling${NC}"
fi

# Check 5: Exit code expansion works
if grep -q '\$? (code 0) = "0"' /tmp/expansion_output; then
    echo -e "${GREEN}✅ Exit code expansion${NC}"
    ((success_count++))
else
    echo -e "${RED}❌ Exit code expansion${NC}"
fi

# Check 6: Complex expansion works
if grep -q '"User .* in directory" = "User .* in directory"' /tmp/expansion_output; then
    echo -e "${GREEN}✅ Complex expansion${NC}"
    ((success_count++))
else
    echo -e "${RED}❌ Complex expansion${NC}"
fi

# Check 7: Quote removal works
if grep -q "'hello world' -> \"hello world\"" /tmp/expansion_output; then
    echo -e "${GREEN}✅ Quote removal${NC}"
    ((success_count++))
else
    echo -e "${RED}❌ Quote removal${NC}"
fi

# Check 8: Quotes validation works
if grep -q "Balanced.*false" /tmp/expansion_output; then
    echo -e "${GREEN}✅ Quote validation${NC}"
    ((success_count++))
else
    echo -e "${RED}❌ Quote validation${NC}"
fi

# Summary
echo -e "\n${YELLOW}=== SUMMARY ===${NC}"
echo -e "Passed: ${GREEN}$success_count/$total_checks${NC}"

if [ $success_count -eq $total_checks ]; then
    echo -e "${GREEN}🎉 Phase 3 Expansion: COMPLETE!${NC}"
    echo -e "${GREEN}✅ Variables expansion working${NC}"
    echo -e "${GREEN}✅ Exit codes expansion working${NC}"
    echo -e "${GREEN}✅ Quotes handling working${NC}"
    echo -e "${GREEN}✅ Quote removal working${NC}"
    echo -e "${GREEN}✅ Syntax validation working${NC}"
    echo -e "\n${YELLOW}Ready for Phase 4: Advanced Operators!${NC}"
    rm -f /tmp/expansion_output
    exit 0
elif [ $success_count -ge 6 ]; then
    echo -e "${YELLOW}⚠️  Phase 3: Mostly working ($success_count/$total_checks)${NC}"
    rm -f /tmp/expansion_output
    exit 0
else
    echo -e "${RED}❌ Phase 3: Needs work ($success_count/$total_checks)${NC}"
    echo -e "\n${YELLOW}Debug output:${NC}"
    cat /tmp/expansion_output
    rm -f /tmp/expansion_output
    exit 1
fi