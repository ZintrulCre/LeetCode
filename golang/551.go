func checkRecord(s string) bool {
    a, l := 0, 0
    for i := 0; i < len(s); i++ {
        if s[i] == \u0027L\u0027 {
            l++
        } else {
            l = 0
        }
        if s[i] == \u0027A\u0027 {
            a++
        }
        if (a >= 2 || l >= 3) {
            return false
        }
    }
    return true
}
