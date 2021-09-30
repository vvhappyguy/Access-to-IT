#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

const int kRows = 9;
const int kColumn = 9;

const int kVariants = 9;

int empty = kRows * kColumn;

class Node
{
public:
    Node(){};
    friend bool operator==(const Node &lhs, const Node &rhs) { return &lhs.value == &rhs.value; };
    friend bool operator!=(const Node &lhs, const Node &rhs) { return !(lhs == rhs); };
    int value = 0;
    std::vector<Node> *row;
    // std::vector<Node &> *column;
    // std::vector<Node &> *square;
    std::vector<int> possibleVariants = {1, 2, 3, 4, 5, 6, 7, 8, 9};
};

void analyzeLines(std::vector<std::vector<Node>> &table)
{
    // Analyze lines
    for (auto &row : table)
    {
        for (auto &elem : row)
        {
            if (elem.value == 0)
            {
                for (auto near : row)
                {
                    if (near != elem)
                    {
                        if (near.value != 0)
                        {
                            elem.possibleVariants.erase(std::remove(elem.possibleVariants.begin(), elem.possibleVariants.end(), near.value), elem.possibleVariants.end());
                        }
                    }
                }
            }
        }
    }
}

void analyzeColumns(std::vector<std::vector<Node>> &table)
{
    // Analyze columns
    int rowE = 0, colE = 0;
    int rowComp = 0, colComp = 0;

    for (auto &row : table)
    {
        rowE++;
        for (auto &elem : row)
        {
            colE = (colE + 1) % 9;
            if (elem.value == 0)
            {
                //std::cout << "Elem[" << rowE << "][" << colE << "]" << std::endl;
                for (const auto &rowC : table)
                {
                    rowComp++;

                    for (const auto &near : rowC)
                    {
                        colComp = (colComp + 1) % 9;
                        if (near != elem)
                        {
                            if (rowComp != rowE)
                            {
                                if (colComp == colE)
                                {
                                    elem.possibleVariants.erase(std::remove(elem.possibleVariants.begin(), elem.possibleVariants.end(), near.value), elem.possibleVariants.end());
                                }
                            }
                        }
                    }
                }
                rowComp = 0;
                colComp = 0;
            }
        }
    }
}

void analyzeSquares(std::vector<std::vector<Node>> &table)
{
    // Analyze columns
    int rowE = 0, colE = 0;
    int rowComp = 0, colComp = 0;

    for (auto &row : table)
    {
        rowE++;
        for (auto &elem : row)
        {
            colE++;
            if (elem.value == 0)
            {
                //std::cout << "Elem[" << rowE << "][" << colE << "]" << std::endl;
                for (const auto &rowC : table)
                {
                    rowComp++;

                    for (const auto &near : rowC)
                    {
                        colComp++;
                        if (near != elem)
                        {
                            if (rowComp != rowE)
                            {
                                if (colComp != colE)
                                {
                                    if ((colComp - 1) / 3 == (colE - 1) / 3 && (rowComp - 1) / 3 == (rowE - 1) / 3)
                                    {
                                        // std::cout << "1: " << rowComp << " " << colComp << std::endl;
                                        // std::cout << rowE << " " << colE << std::endl;
                                        elem.possibleVariants.erase(std::remove(elem.possibleVariants.begin(), elem.possibleVariants.end(), near.value), elem.possibleVariants.end());
                                    }
                                }
                            }
                        }
                    }
                    colComp = 0;
                }
                rowComp = 0;
            }
        }
        colE = 0;
    }
}

void putIn(std::vector<std::vector<Node>> &table)
{
    // Put in-ing
    int i = 0, j = 0;
    for (auto &row : table)
    {
        i++;
        for (auto &elem : row)
        {
            j++;
            if (elem.value == 0 && elem.possibleVariants.size() == 1)
            {
                elem.value = elem.possibleVariants[0];
                // std::cout << "[" << i << "][" << j << "] = " << elem.value << std::endl;
                empty--;
            }
        }
    }
}

int main(int args, char *argv[])
{
    std::vector<std::vector<Node>> table;

    // Init table
    for (int rowNumber = 0; rowNumber < kRows; ++rowNumber)
    {
        std::vector<Node> row;
        for (int columnNumber = 0; columnNumber < kColumn; ++columnNumber)
        {
            Node node;
            std::string input;
            std::cin >> input;
            node.row = &row;
            node.value = std::stoi(input);
            if (node.value != 0)
            {
                empty--;
                node.possibleVariants = {};
            }
            row.push_back(node);
        }
        table.push_back(row);
    }

    // Just output
    // for (const auto &rowNumber : table)
    // {
    //     for (const auto &elem : rowNumber)
    //     {
    //         std::cout << elem.value << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // std::cout << "Empty = " << empty;
    const int before = empty;

    int lastEmpty = empty;
    int cycles = 0;
    int tries = 0;
    while (empty != 0)
    {
        cycles += 1;
        analyzeLines(table);
        analyzeColumns(table);
        analyzeSquares(table);
        putIn(table);
        if (empty == lastEmpty)
        {
            tries++;
            if (tries == 5)
            {
                tries = 0;
                break;
            }
        }
        else
        {
            lastEmpty = empty;
        }
    }

    // // Just output
    //std::cout << std::endl;
    for (const auto rowNumber : table)
    {
        for (const auto elem : rowNumber)
        {
            std::cout << elem.value << " ";
        }
        std::cout << std::endl;
    }
    if (empty != 0)
    {
        std::cout << "Can't solve this" << std::endl;
    }
    std::cout << "Empty = " << empty << " of before " << before << std::endl
              << cycles << std::endl;
    for (const auto rowNumber : table)
    {
        for (const auto elem : rowNumber)
        {
            if (elem.possibleVariants.size() <= 2)
            {
                for (const auto n : elem.possibleVariants)
                {
                    std::cout << n << std::endl;
                }
            }
        }
    }
    return 0;
}