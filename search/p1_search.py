"""
Alice has some cards with numbers written on them.
She arranges the cards in decreasing order, and lays them out face down in a sequence on a table.
She challenges Bob to pick out the card containing a given number by turning over as few cards as possible.
Write a function to help Bob locate the card.
"""

tests = [
    # query is middle element
    {
        "input": {
            "cards": [13, 11, 10, 7, 4, 3, 1, 0],
            "query": 7,
        },
        "output": 3
    },
    # query is first element
    {
        "input": {
            "cards": [4, 2, 1, -1],
            "query": 4,
        },
        "output": 0
    },
    # query is last element
    {
        "input": {
            "cards": [3, -1, -9, -127],
            "query": -127,
        },
        "output": 3
    },
    # cards contains just one element, query
    {
        "input": {
            "cards": [3],
            "query": 3,
        },
        "output": 0
    },
    # cards does not contain query
    {
        "input": {
            "cards": [9, 7, 5, 2, -9],
            "query": 4,
        },
        "output": -1
    },
    # cards is empty
    {
        "input": {
            "cards": [],
            "query": 4,
        },
        "output": -1
    },
    # numbers can repeat in cards
    {
        "input": {
            "cards": [8, 8, 6, 6, 6, 6, 6, 6, 3, 2, 2, 2, 0, 0, 0, 0],
            "query": 3,
        },
        "output": 8
    },
    {
        "input": {
            "cards": [8, 8, 6, 6, 6, 6, 6, 6, 3, 2, 2, 2, 0, 0, 0, 0],
            "query": 6,
        },
        "output": 2
    }
]


def locate_card_linear(cards, query):
    """
        Time Complexity: O(n)
    """
    # Initial position
    position = 0

    # Number of cards
    n = len(cards)
    if n == 0:
        return -1

    while True:
        # if query is list return position
        if cards[position] == query:
            return position

        # otherwise increase the position
        position += 1

        # if card not found
        if position == n:
            return -1


def locate_card_binary(cards, query):
    """
        Time Complexity: O(log n)
    """
    pos = binary_search(cards, query, 0, len(cards)-1)
    return get_first_loc(cards, pos)


def binary_search(input_list, value, low, high):
    if len(input_list) == 0 or high < low:
        return -1
    mid_pos = (low+high) // 2
    if value == input_list[mid_pos]:
        return mid_pos
    elif value > input_list[mid_pos]:
        return binary_search(input_list, value, low, mid_pos-1)
    else:
        return binary_search(input_list, value, mid_pos+1, high)


def get_first_loc(cards, pos):
    if pos-1 >= 0 and cards[pos] == cards[pos-1]:
        return get_first_loc(cards, pos-1)
    else:
        return pos


for test in tests:
    result = locate_card_linear(test["input"]["cards"], test["input"]["query"])
    print("Test Case: ", test, "Test pass:", result == test["output"])

print("----------------------------------------------------------------------------")

for test in tests:
    result = locate_card_binary(test["input"]["cards"], test["input"]["query"])
    print("Test Case: ", test, "Test pass:", result == test["output"])
