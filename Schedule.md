# FTL analysis project
- The topics to be implemented or analyzed
    1. Data erase: Data cannot be overwrite in nand flash (data should be erased before re-written)
    2. Garbage collect (GC)
    3. Wear counter (nand flash life management): life time and reliability
    4. Write Amlification analysis (based on different GC/else algorithm)
    5. Fault data detection and correction (Error handling flow or mitigation policy)
- The functionailities to be comleted
    1. Abstract NAND flash storage
    2. Mapping Table
    3. GC algorithm
    4. Write Amplification calculation function
    5. Workload (Data to be stored) generator
    6. log & static

- The expected functionalities and components
    1. Mapping Table (page based)
    2. Garbage collections
        - The condition to triggered GC, the possibly options are as follows:
            - The free blocks (or pages) is less than threshold
                

- The essentials to be defined
    - Abstract logical NAND flash heirachy
        - The mapping table ( page-based, block-based or hybrid-based ) is depended on the heirachy.
        - How to read/write data in abstract logical NAND flash
    - Basic unit of read/write/erase operation
    - What is the data structure design of mapping table?
        - What information should be recorded in mapping table?
            - Valid/Invalid
            - Wear counter
    - GC mechanism
        - How to and when should triggers GC
        - Hot data & cold data
    - What is the data structure of workload (data to be stored)?
    - Over-provision (OP)
        - Size

- Options (not urgent)
    - If GC is triggered when free space less than threshold.
        1. How to define a proper value of threshold?
        2. The threshold should be a fixed or non-fixed value?

# schedule step
1. JD需求對應的研究面向
    - SSD NAND flash演算法開發：GC、Wear leveling、Mapping table設計、Write Amplification分析
    - Backend NAND效能演算法：GC觸發條件、熱/冷資料管理、OP設計
    - 資料錯誤修正流程：Fault data detection/correction、ECC流程設計
    - 演算法實作與驗證：模擬NAND操作、效能統計、log分析
    - 客戶需求調校SSD效能：可調參數設計（GC threshold、OP size等）
    - 資料結構規劃

2. Data（Workload）：模擬資料流，設計熱/冷資料分布
    - Mapping Table：記錄邏輯到物理頁/區塊映射、有效/無效標記、wear counter
    - Abstract NAND Flash：建議要做，方便模擬不同層級（頁、區塊、晶片）操作
    - GC/OP管理結構：記錄空閒、有效、無效頁/區塊狀態
3. 功能規劃
    - Abstract NAND flash storage（模擬NAND操作）
    - Mapping Table管理
    - GC演算法與觸發條件
    - Wear leveling與壽命統計
    - Write Amplification計算
    - Workload generator（資料流模擬）
    - Fault data detection/correction（ECC流程）
    - log/statistics收集與分析
    - 可調參數設計（GC threshold、OP size等）
* 建議規劃順序：
    - 明確定義NAND Flash抽象層級與基本操作（read/write/erase）
    - 設計Mapping Table與資料結構（包含wear counter、有效/無效標記）
    - 規劃Workload generator（模擬資料流）
    - 實作GC與Wear leveling演算法
    - 加入Write Amplification計算與統計
    - 設計Fault data detection/correction流程
    - log/statistics收集與可調參數設計
    - 整合測試與效能驗證

# File management
    - Data Structure to be defined:
        - Abstract Nand flash
        - mapping table
            - valid/invalid
            - logic address/physical address
                - address format
            - wear counter
            - op space

# 建議檔案與目錄結構
- src/：主要程式碼目錄（建議將所有核心功能集中於此）
    - nand_flash.py / .c：抽象NAND Flash操作
    - mapping_table.py / .c：映射表管理
    - gc.py / .c：垃圾回收演算法
    - wear_leveling.py / .c：wear leveling相關
    - workload.py / .c：workload產生器
    - error_correction.py / .c：錯誤修正流程
    - utils.py / .c：公用函式（如log、統計等）
- main.py / .c：主程式，負責流程控制與分析執行
- config/：參數設定檔（如json/yaml/txt，方便調整GC threshold、OP size等）
- tests/：單元測試與驗證腳本
- docs/：設計說明、流程圖、效能分析
- logs/：執行紀錄與統計資料