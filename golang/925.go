func isLongPressedName(name string, typed string) bool {
\u0009name_size, typed_size := len(name), len(typed)
\u0009i, j := 0, 0
\u0009for i < name_size && j < typed_size {
\u0009\u0009if name[i] == typed[j] {
\u0009\u0009\u0009i++
\u0009\u0009\u0009j++
\u0009\u0009} else {
\u0009\u0009\u0009j++
\u0009\u0009}
\u0009}
\u0009if i == name_size { 
\u0009\u0009return true
\u0009}
\u0009return false
}
