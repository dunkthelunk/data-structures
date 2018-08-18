package pojo;

public class Trie {

  private TrieNode genTrieNode;

  private static Trie instance;

  public static Trie getInstance() {
    if (instance == null) {
      synchronized (Trie.class) {
        if (instance == null) {
          instance = new Trie();
        }
      }
    }
    return instance;
  }

  private Trie() {
    genTrieNode = new TrieNode(' ');
  }

  public void put(String numberString) {
    TrieNode currentTrieNode = genTrieNode;
    for(int i = 0; i < numberString.length(); i++) {
      char c = numberString.charAt(i);
      currentTrieNode = currentTrieNode.addAndReturnChildWithChar(c);
    }
  }

  public boolean containsString(String fullString) {
    TrieNode currentTrieNode = genTrieNode;
    for(int i = 0; i < fullString.length(); i++) {
      char c = fullString.charAt(i);
      if (currentTrieNode.hasChildWithChar(c)) {
        currentTrieNode = currentTrieNode.getChildWithChar(c);
      }
      else {
        return false;
      }
    }
    return !currentTrieNode.hasChildren();
  }

}
