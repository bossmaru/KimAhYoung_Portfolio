
## **프로젝트 설명**
언리얼 엔진 5로 개발된 게임 프로젝트로, 다양한 AI 로직, 캐릭터 스탯 관리, 인벤토리 시스템, 그리고 플레이어와 NPC 간 상호작용 등을 포함하고 있습니다.

---

## **기술 스택**
- **언리얼 엔진 4**
- **C++**
- **Blueprints (블루프린트)**
- **Behavior Tree / Blackboard**
- **UMG (Unreal Motion Graphics)**
- **Enhanced Input System**

---

## **주요 컴포넌트 설명**

### **AI 시스템**
- **`AMyAIController`**: Behavior Tree를 사용하여 AI의 행동을 제어.
- **`BTTask_SetRandomPos`, `BTTask_SetTargetPos`**: AI가 랜덤 위치를 설정하거나 타겟 위치를 설정하는 태스크를 수행.
- **`BTService_FindTarget`, `BTService_PrimeSetting`**: 타겟을 탐색하거나 프라임 위치를 설정하는 서비스.

### **캐릭터 클래스**
- **`AMyPlayer`, `AKnight`, `AArcher`, `AMyMonster`, `AMyNPC`**: 다양한 캐릭터 클래스가 있으며, 각 캐릭터는 고유한 공격 방식과 애니메이션을 가지고 있음.
- **전투 시스템**: `AttackHit` 함수와 애니메이션 몽타주를 사용하여 공격을 처리합니다.
- **`UMyAnimInstance`**: 캐릭터 애니메이션을 관리하고 공격 및 데미지 처리 시 몽타주 재생.

### **인벤토리 시스템**
- **`UMyInventoryUI`**: 플레이어가 수집한 아이템을 관리할 수 있는 인벤토리 UI. 아이템을 추가하거나 삭제 가능.
- **`UMyInventoryComponent`**: 인벤토리에 아이템을 추가하거나 드롭할 수 있는 기능 제공.
- **`AMyItem`**: 게임 내 아이템을 관리하는 클래스.

### **상점 시스템**
- **`UMyStoreUI`**: 플레이어가 NPC와 상호작용하여 아이템을 거래할 수 있는 상점 UI.
- **`AMyNPC`**: 상점과 같은 상호작용을 제공하는 NPC 클래스.

### **UI 관리 시스템**
- **`AMyUIManager`**: 인벤토리, 상점, 플레이어 선택 등 다양한 UI를 관리하고 토글할 수 있는 기능을 제공.
- **`UPlayerSelectionUI`**: 게임 시작 시 플레이어가 선택할 캐릭터를 선택하는 UI.

### **스탯 관리 시스템**
- **`UMyStatComponent`**: 각 캐릭터의 스탯(체력, 공격력 등)을 관리. 스탯 변경 시 UI 업데이트 및 이벤트를 처리.

### **플레이어 관리 시스템**
- **`AMyPlayerManager`**: 게임 내에서 플레이어의 타입(예: Knight 또는 Archer)을 설정하고, 선택된 플레이어에 따라 캐릭터를 관리.
