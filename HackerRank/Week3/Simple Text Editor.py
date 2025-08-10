#!/bin/python3

import sys

def simple_text_editor(operations):
    text = ""            # Current string
    history = []         # Stack to store history for undo
    output = []          # Results for print commands

    for op in operations:
        parts = op.split()
        t = int(parts[0])

        if t == 1:  # append
            history.append(text)     # Save state before change
            text += parts[1]

        elif t == 2:  # delete
            k = int(parts[1])
            history.append(text)     # Save state before change
            text = text[:-k]

        elif t == 3:  # print
            k = int(parts[1])
            output.append(text[k-1])

        elif t == 4:  # undo
            text = history.pop()     # Restore last saved state

    return output


if __name__ == '__main__':
    q = int(sys.stdin.readline())
    operations = [sys.stdin.readline().strip() for _ in range(q)]
    
    result = simple_text_editor(operations)
    print("\n".join(result))
