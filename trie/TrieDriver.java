package main;

import pojo.Trie;

public class TrieDriver {
  public static void main(String[] args) {
    Trie trie = Trie.getInstance();
    trie.put("prudhvi");
    trie.put("glazzies");
    trie.put("88796856");
    System.out.println(trie.containsString("pru"));
    System.out.println(trie.containsString("prudv"));
    System.out.println(trie.containsString("glazzies"));
    System.out.println(trie.containsString("887926856"));
    System.out.println(trie.containsString("88796856"));
  }
}
