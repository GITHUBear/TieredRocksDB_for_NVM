#pragma once

#include "db/compaction/compaction_picker.h"

namespace rocksdb {
    class TierCompactionPicker : public CompactionPicker {
    public:    
        TierCompactionPicker(const ImmutableCFOptions& ioptions,
                              const InternalKeyComparator* icmp)
            : CompactionPicker(ioptions, icmp) {}
        virtual Compaction* PickCompaction(const std::string& cf_name,
                                           const MutableCFOptions& mutable_cf_options,
                                           VersionStorageInfo* vstorage,
                                           LogBuffer* log_buffer) override;
        virtual bool NeedsCompaction(
            const VersionStorageInfo* vstorage) const override;
    };
}