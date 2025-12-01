#pragma once
#include "pch.h"
#include <memory>

// 호준 추가 
template<typename T>
    class ObjectPool
{
public:
    ObjectPool() = default;

    ~ObjectPool()
    {
        for (auto& obj : m_Objects)
        {
            // unique_ptr을 소멸
        }

        m_Objects.clear();
    }

	void Initialize(size_t maxCount)
	{
        m_Objects.clear();
        m_Objects.reserve(maxCount);

        for (size_t i = 0; i < maxCount; ++i)
        {
            unique_ptr<T> ptr = make_unique<T>();
            ptr->Initialize();     // 최초 1회 초기화
            // 생성 직후에는 아직 Activate 안 했으므로 m_bInUse = false
            m_Objects.push_back(move(ptr));
        }
	}

    T* Acquire()
    {
        for (auto& obj : m_Objects)
        {
            if (!obj->IsInUse())
            {
                obj->Activate();
                return obj.get();
            }
        }

        // 풀에 빈 슬롯이 없을 때 처리 지금은 nullptr 반환
        return nullptr;
    }

    // 활성 객체들만 순회
    template<typename Func>
    void ForEachActivate(Func func)
    {
        for (auto& obj : m_Objects)
        {
            if (obj->IsInUse())
            {
                func(*obj);
            }
        }
    }

    // 전체 비활성화 (씬 리셋 등 필요 시)
    void DeactivateAll()
    {
        for (auto& obj : m_Objects)
        {
            if (obj->IsInUse())
            {
                obj->Deactivate();
            }
        }
    }

private:
	std::vector<unique_ptr<T>> m_Objects;
};
