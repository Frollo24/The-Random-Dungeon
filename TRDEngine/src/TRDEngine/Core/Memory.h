#pragma once

#include "TRDPCH.h"

namespace TRDEngine {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	template<class T, class U>
	constexpr Ref<T> StaticCast(Ref<U> ref) { return std::static_pointer_cast<T>(ref); }
	template<class T, class U>
	constexpr Ref<T> DynamicCast(Ref<U> ref) { return std::dynamic_pointer_cast<T>(ref); }

	template<typename T>
	using WeakRef = std::weak_ptr<T>;

}