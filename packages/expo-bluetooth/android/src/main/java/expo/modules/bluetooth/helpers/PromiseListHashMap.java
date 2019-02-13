package expo.modules.bluetooth.helpers;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedHashMap;

import expo.core.Promise;

public class PromiseListHashMap<K, V> extends HashMap<K, V> {

  public PromiseListHashMap() {
    super();
  }

  @Override
  public V put(K key, V value) {
    ensureKey(key);
    return super.put(key, value);
  }

  public void ensureKey(K key) {
    if (!this.containsKey(key)) {
      this.put(key, (V) new ArrayList<>());
    }
  }

  public void add(K key, Promise value) {
    ensureKey(key);
    ArrayList<Promise> list = (ArrayList<Promise>) get(key);
    list.add(value);
  }

  public void clearKey(K key) {
    ensureKey(key);
    remove(key);
  }
}
