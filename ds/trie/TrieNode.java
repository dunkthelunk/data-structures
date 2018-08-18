package pojo;

import java.util.Arrays;
import java.util.Objects;

public class TrieNode {

  private char letter;
  private TrieNode[] children;

  TrieNode(char digit) {
    letter = digit;
    children = new TrieNode[36];
  }

  boolean hasChildWithChar(char c) {
    return children[Alphabet.positionOf(c)] != null;
  }

  TrieNode getChildWithChar(char c) {
    if (hasChildWithChar(c)) {
      return children[Alphabet.positionOf(c)];
    }
    return null;
  }

  private void addChild(TrieNode child) {
    children[Alphabet.positionOf(child.letter)] = child;
  }

  TrieNode addAndReturnChildWithChar(char letter) {
    TrieNode child = new TrieNode(letter);
    addChild(child);
    return child;
  }

  public boolean hasChildren() {
    return Arrays.stream(children).anyMatch(Objects::nonNull);
  }
}
