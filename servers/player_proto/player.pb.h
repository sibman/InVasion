// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: player.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_player_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_player_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3018000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3018001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_player_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_player_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_player_2eproto;
class PlayerAction;
struct PlayerActionDefaultTypeInternal;
extern PlayerActionDefaultTypeInternal _PlayerAction_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::PlayerAction* Arena::CreateMaybeMessage<::PlayerAction>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

enum PlayerAction_Action : int {
  PlayerAction_Action_Idle = 0,
  PlayerAction_Action_StartMovingUp = 1,
  PlayerAction_Action_StartMovingRight = 2,
  PlayerAction_Action_StartMovingDown = 3,
  PlayerAction_Action_StartMovingLeft = 4,
  PlayerAction_Action_StopMovingUp = 5,
  PlayerAction_Action_StopMovingRight = 6,
  PlayerAction_Action_StopMovingDown = 7,
  PlayerAction_Action_StopMovingLeft = 8,
  PlayerAction_Action_PlayerAction_Action_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  PlayerAction_Action_PlayerAction_Action_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool PlayerAction_Action_IsValid(int value);
constexpr PlayerAction_Action PlayerAction_Action_Action_MIN = PlayerAction_Action_Idle;
constexpr PlayerAction_Action PlayerAction_Action_Action_MAX = PlayerAction_Action_StopMovingLeft;
constexpr int PlayerAction_Action_Action_ARRAYSIZE = PlayerAction_Action_Action_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PlayerAction_Action_descriptor();
template<typename T>
inline const std::string& PlayerAction_Action_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PlayerAction_Action>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PlayerAction_Action_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    PlayerAction_Action_descriptor(), enum_t_value);
}
inline bool PlayerAction_Action_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PlayerAction_Action* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<PlayerAction_Action>(
    PlayerAction_Action_descriptor(), name, value);
}
// ===================================================================

class PlayerAction final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:PlayerAction) */ {
 public:
  inline PlayerAction() : PlayerAction(nullptr) {}
  ~PlayerAction() override;
  explicit constexpr PlayerAction(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PlayerAction(const PlayerAction& from);
  PlayerAction(PlayerAction&& from) noexcept
    : PlayerAction() {
    *this = ::std::move(from);
  }

  inline PlayerAction& operator=(const PlayerAction& from) {
    CopyFrom(from);
    return *this;
  }
  inline PlayerAction& operator=(PlayerAction&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PlayerAction& default_instance() {
    return *internal_default_instance();
  }
  static inline const PlayerAction* internal_default_instance() {
    return reinterpret_cast<const PlayerAction*>(
               &_PlayerAction_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PlayerAction& a, PlayerAction& b) {
    a.Swap(&b);
  }
  inline void Swap(PlayerAction* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PlayerAction* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline PlayerAction* New() const final {
    return new PlayerAction();
  }

  PlayerAction* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PlayerAction>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PlayerAction& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const PlayerAction& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PlayerAction* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "PlayerAction";
  }
  protected:
  explicit PlayerAction(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef PlayerAction_Action Action;
  static constexpr Action Idle =
    PlayerAction_Action_Idle;
  static constexpr Action StartMovingUp =
    PlayerAction_Action_StartMovingUp;
  static constexpr Action StartMovingRight =
    PlayerAction_Action_StartMovingRight;
  static constexpr Action StartMovingDown =
    PlayerAction_Action_StartMovingDown;
  static constexpr Action StartMovingLeft =
    PlayerAction_Action_StartMovingLeft;
  static constexpr Action StopMovingUp =
    PlayerAction_Action_StopMovingUp;
  static constexpr Action StopMovingRight =
    PlayerAction_Action_StopMovingRight;
  static constexpr Action StopMovingDown =
    PlayerAction_Action_StopMovingDown;
  static constexpr Action StopMovingLeft =
    PlayerAction_Action_StopMovingLeft;
  static inline bool Action_IsValid(int value) {
    return PlayerAction_Action_IsValid(value);
  }
  static constexpr Action Action_MIN =
    PlayerAction_Action_Action_MIN;
  static constexpr Action Action_MAX =
    PlayerAction_Action_Action_MAX;
  static constexpr int Action_ARRAYSIZE =
    PlayerAction_Action_Action_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  Action_descriptor() {
    return PlayerAction_Action_descriptor();
  }
  template<typename T>
  static inline const std::string& Action_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Action>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Action_Name.");
    return PlayerAction_Action_Name(enum_t_value);
  }
  static inline bool Action_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      Action* value) {
    return PlayerAction_Action_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kKeyPressedFieldNumber = 1,
  };
  // .PlayerAction.Action key_pressed = 1;
  void clear_key_pressed();
  ::PlayerAction_Action key_pressed() const;
  void set_key_pressed(::PlayerAction_Action value);
  private:
  ::PlayerAction_Action _internal_key_pressed() const;
  void _internal_set_key_pressed(::PlayerAction_Action value);
  public:

  // @@protoc_insertion_point(class_scope:PlayerAction)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  int key_pressed_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_player_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PlayerAction

// .PlayerAction.Action key_pressed = 1;
inline void PlayerAction::clear_key_pressed() {
  key_pressed_ = 0;
}
inline ::PlayerAction_Action PlayerAction::_internal_key_pressed() const {
  return static_cast< ::PlayerAction_Action >(key_pressed_);
}
inline ::PlayerAction_Action PlayerAction::key_pressed() const {
  // @@protoc_insertion_point(field_get:PlayerAction.key_pressed)
  return _internal_key_pressed();
}
inline void PlayerAction::_internal_set_key_pressed(::PlayerAction_Action value) {
  
  key_pressed_ = value;
}
inline void PlayerAction::set_key_pressed(::PlayerAction_Action value) {
  _internal_set_key_pressed(value);
  // @@protoc_insertion_point(field_set:PlayerAction.key_pressed)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::PlayerAction_Action> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::PlayerAction_Action>() {
  return ::PlayerAction_Action_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_player_2eproto
