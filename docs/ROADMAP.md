# 🚀 Turquaz - Geliştirme Yol Haritası 

Bu dosya projenin gelişim sürecini takip etmek için oluşturulmuştur. Her aşama üzerine tartışılarak ve onaylanarak geçilecektir.

---

## 🛡️ I. Bölüm: Temeller ve Proje Bağlamı 
*Amaç: Projenin 'Anayasasını' ve bellek stratejisini belirlemek.*

- [ x ] **1. Klasör Yapısı:** Modüler hiyerarşinin kurulması.
- [ x ] **2. ProjectContext:** Dimension (2D/3D) ve DimensionType (PixelArt/Realistic) verilerini tutan sınıf.
- [ x ] **3. Settings Parser:** Kodun başındaki ayar bloğunu okuyan 'Asistan' özellikli parser.
- [ x ] **4. Memory Manager:** Arena Allocation (Havuz Bellek) ve Dinamik mod seçicisi.
- [  ] **4. File Manager:** tqs uzantılı dosyaları bulacak, içeriğini okuyacak.

---

## 🔍 II. Bölüm: Dilin Kelimeleri ve Grameri 
*Amaç: Metni bilgisayarın anlayabileceği yapısal verilere (AST) dönüştürmek.*

- [ ] **5. Lexer:** Kaynak kodu simgelere (Token) parçalama.
- [ ] **6. Parser:** Syntax kurallarının ve hiyerarşinin kontrolü.
- [ ] **7. Scope Manager:** Değişkenlerin yaşam alanlarının (Scope) yönetimi.
- [ ] **8. Dimension Guard:** Boyut kısıtlamalarının (2D vs 3D) ilk kontrol noktası.

---

## ⚙️ III. Bölüm: Anlam ve Hızlandırma 
*Amaç: Kodun doğruluğunu teyit etmek ve performans optimizasyonlarını yapmak.*

- [ ] **9. Semantic Analyzer:** Tip kontrolü ve detaylı hata/uyarı raporlama sistemi.
- [ ] **10. Intermediate Representation (IR):** Kodun optimize edilebilir ara formuna geçiş.
- [ ] **11. Constant Folding:** Derleme aşamasında matematiksel ön-hesaplamalar.
- [ ] **12. Bytecode Generator:** Register-based VM için sayısal komut üretimi.

---

## 🚀 IV. Bölüm: Sanal Makine ve Motor Bağlantısı 
*Amaç: Kodun C++ oyun motoru ile entegre bir şekilde çalıştırılması.*

- [ ] **13. Register-Based VM:** Yüksek performanslı ana komut işleyici.
- [ ] **14. Native Bridge:** C++ fonksiyonlarının (Move, Rotate vb.) script'e bağlanması.
- [ ] **15. Event System:** Start/Update döngülerinin motorla senkronizasyonu.
- [ ] **16. Hot-Reload:** Oyun kapanmadan kod değişikliği desteği.

---

## ⚙️ V. Bölüm: Yükleme İşlemi
*Amaç: Yükleme sırasında en az kafa karışıklığı ile proje başında gerekli ayarlar ile kurulumun sağlanması*
- [ ] **17. Installer:** kurulum için gerekli cmd komutları oluşturma.
- [ ] **18. File Association:** `.tqs` uzantısının Turquaz ile ilişkilendirilmesi.
- [ ] **19. Project Installer:** proje oluşturma cmd komutları oluşturma.

---

## 💎 VI. Bölüm: Kullanıcı Deneyimi ve Yayın 
*Amaç: Geliştiricinin işini kolaylaştıran yan araçların eklenmesi.*

- [ ] **20. Debugger Lite:** Hata takibi ve değişken izleme araçları.
- [ ] **21. Auto-Doc:** Koddan otomatik dökümantasyon taslağı üretme.
- [ ] **22. Standard Library:** Hazır matematik ve fizik kütüphaneleri.
- [ ] **23. İlk Demo:** Dil ile yazılmış çalışan bir oyun örneği.